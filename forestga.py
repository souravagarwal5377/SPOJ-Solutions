n,w,mh=map(int,raw_input().split())
a=[]
r=[]
n=(int)(n)
w=(int)(w)
mh=(int)(mh)
for i in range(0,n):
	x,y=map(int,raw_input().split())
	a.append(x)
	r.append(y)
l=(int)(0)
u=ans=(int)(1000000000000000000)
while(l<u):
    m=(int)((l+u)/2)
    g=(int)(0)
    for i in range(0,n):
        xx=(int)((a[i]+r[i]*m)/mh)
        xx=xx*mh
        g=g+xx
    if(g>=w):
        if(m<ans):
            ans=m
        u=m
    else:
        l=m+1
print(ans)