def fact(n):
	if(n==0):
		return 1
	else:
		return n*fact(n-1)

t=int(input())
for i in range(t):
	n,k=raw_input().split(" ")
	n=int(n)
	k=int(k)
	x=fact(n-1)
	y=fact(r-1)
	z=fact(n-r)
	ans=int(x/(y*z))
	print(ans)