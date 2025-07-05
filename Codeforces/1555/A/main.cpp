import math

def solve():
    n = int(input())
    if n <= 6:
        print(15)
        return
    
    ans = (n // 6) * 15
    n %= 6
    if n <= 0:
        ans += 0
    elif n <= 2:
        ans += 5
    elif n <= 4:
        ans += 10
    else:
        ans += 15
    print(ans)

t = int(input())
while t > 0:
    solve()
    t -= 1
