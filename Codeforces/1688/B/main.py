def solve():
    n=int(input())
    a=list(map(int, input().split()))
    min_v2=100000000
    num_even=0
    num_odd=0
    for i in range(n):
        if(a[i]%2==1):
            num_odd=1
        if(a[i]%2==0):
            num_even+=1
            counter=0
            while(a[i]%2==0):
                a[i]=a[i]//2
                counter+=1
            if(counter<min_v2):
                min_v2=counter
    if(num_odd>0):
        return num_even
    elif(num_odd==0 and num_even>0):
        return num_even+min_v2-1
    else: 
        return 0

def main():
    t=int(input())
    for _ in range(t):
        print(solve())

main()
