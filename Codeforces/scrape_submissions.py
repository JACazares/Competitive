import os
import subprocess
import requests
import threading
import webbrowser
import pyperclip  # Ensure you have installed this package: pip install pyperclip
import platform
import time
import sys
import select
import random

# Configuration
API_URL = "https://codeforces.com/api/user.status?handle=joseacaz"
BASE_DIR = os.path.expanduser("~/Desktop/Programming/Competitive/Codeforces")

def wait_for_clipboard_change_or_enter(initial_clipboard):
    """
    Blocks until either the clipboard content changes from the initial value
    or the user presses Enter. This implementation uses a single loop that
    checks both conditions without creating additional threads.
    """
    print("After copying the submission code, press Enter or wait for the clipboard to change...")
    while True:
        # Check if the clipboard has changed
        if pyperclip.paste() != initial_clipboard:
            break
        # Check if the user has pressed Enter (if input is available)
        r, _, _ = select.select([sys.stdin], [], [], 0.2)
        if r:
            sys.stdin.readline()
            break

def open_browser_and_wait(url):
    # Store the initial clipboard content
    initial_clipboard = pyperclip.paste()
    # Open the URL in the default browser
    webbrowser.open(url)
    # Wait until the clipboard changes or Enter is pressed
    try:
        wait_for_clipboard_change_or_enter(initial_clipboard)
    except KeyboardInterrupt:
        print("User stopped the script, likely due to a rate limit")
        exit(1)

def fetch_submissions():
    response = requests.get(API_URL)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch data from Codeforces API. Status code: {response.status_code}")
    data = response.json()
    if data.get("status") != "OK":
        raise Exception("API response not OK.")
    return data["result"]

def filter_latest_submissions(submissions):
    latest_submissions = {}
    for sub in submissions:
        # Use the pair (contestId, problem index) as a unique key.
        contest_id = sub.get("contestId") or sub["problem"].get("contestId")
        problem_index = sub["problem"]["index"]
        key = (contest_id, problem_index)
        # Keep only the submission with the maximum creation time for each problem.
        if key not in latest_submissions or sub["creationTimeSeconds"] > latest_submissions[key]["creationTimeSeconds"]:
            latest_submissions[key] = sub
    return list(latest_submissions.values())

def process_submissions(submissions):
    # Optional: sort submissions by creation time for logical order.
    submissions.sort(key=lambda x: x["creationTimeSeconds"])
    count = 1
    for sub in reversed(submissions):
        contest_id = sub.get("contestId") or sub["problem"].get("contestId")
        problem_index = sub["problem"]["index"]
        file_dir = os.path.join(BASE_DIR, str(contest_id), problem_index)
        file_path = os.path.join(file_dir, "main.cpp")
        
        if os.path.exists(file_path) or os.path.exists(os.path.join(file_dir, "main.py")) or os.path.exists(os.path.join(file_dir, "sol.txt")):
            # print(f"Skipping contest {contest_id} problem {problem_index}: file already exists.")
            continue
        count += 1
    print(f"Processing {count} submissions...")
    for sub in reversed(submissions):
        contest_id = sub.get("contestId") or sub["problem"].get("contestId")
        problem_index = sub["problem"]["index"]
        file_dir = os.path.join(BASE_DIR, str(contest_id), problem_index)
        file_path = os.path.join(file_dir, "main.cpp")
        
        if os.path.exists(file_path) or os.path.exists(os.path.join(file_dir, "main.py")) or os.path.exists(os.path.join(file_dir, "sol.txt")):
            # print(f"Skipping contest {contest_id} problem {problem_index}: file already exists.")
            continue
        
        submission_url = f"https://codeforces.com/contest/{contest_id}/submission/{sub['id']}%3f"
        print(f"Opening submission URL for contest {contest_id} problem {problem_index}:")
        print(submission_url)
        
        # Start timer when opening the webpage
        start_time = time.time()
        open_browser_and_wait(submission_url)
        
        # Ensure at least 5 seconds have passed before proceeding
        elapsed_time = time.time() - start_time
        if elapsed_time < 3:
            time.sleep(3 - elapsed_time)
        
        # Immediately after waiting, grab clipboard content
        code = pyperclip.paste()
        if not code.strip():
            print("No code found in the clipboard. Skipping this submission.")
            continue
        
        os.makedirs(file_dir, exist_ok=True)
        with open(file_path, "w", encoding="utf-8") as f:
            f.write(code)
        print(f"Saved submission for contest {contest_id} problem {problem_index} to {file_path}.\n")

def main():
    try:
        print("Fetching submissions from Codeforces API...")
        submissions = fetch_submissions()
        latest_subs = filter_latest_submissions(submissions)
        print(f"Found {len(latest_subs)} unique problems with submissions.")
        process_submissions(latest_subs)
        print("All submissions have been processed.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()