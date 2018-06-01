t=(int)(raw_input())
while(t>0):
	t=(int)(t-1)
	n,m=map(int,raw_input().split())
	x=(int)(n%m)
	if(x%2==0):
		print("EVEN")
	else:
		print("ODD")

