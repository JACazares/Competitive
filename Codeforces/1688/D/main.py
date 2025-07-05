def solve():
    n, k=map(int, input().split())
    a=list(map(int, input().split()))
    if(n==1):
        return a[0]+k-1
    if(k>=n):
        sum=0
        for b in a:
            sum=sum+b
        return sum+k*(k-1)//2-(k-n)*(k-n-1)//2
    if(k<n):
        sum=0
        for i in range(k):
            sum+=a[i]
        max_sum=sum
        for i in range(k, n):
            sum=sum+a[i]-a[i-k]
            if(sum>max_sum):
                max_sum=sum
        return max_sum+k*(k-1)//2
        



def main():
    t=int(input())
    for _ in range(t):
        print(solve())

main()
