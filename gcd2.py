def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)

t=int(input())
while t:
    a,b=raw_input().split(" ")
    a=int(a)
    b=int(b)
    ans=gcd(a,b)
    print(ans)
    t=t-1
