def solve():
	N = int(input())

	ans = int(N*(N-1)//2);
	print(ans)

if __name__ == "__main__":
	T = int(input())
	while T > 0:
		solve()
		T -= 1

