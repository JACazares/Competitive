t = int(input().strip())

for _ in range(t):
    n, m = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))

    ans = 0
    track = 0
    for i in range(m-1,0,-1):
        track += a[i]
        if track > 0:
            ans += 1
            track -= 2*a[i]
    track = 0
    for j in range(m, n):
        track += a[j]
        if track < 0:
            ans += 1
            track -= 2*a[j]
    print(ans)
