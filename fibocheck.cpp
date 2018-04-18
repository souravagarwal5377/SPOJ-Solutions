//Considers 0th term to be 0 and 1st and 2nd terms to be 1
#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
void multiply(ll a[2][2],ll m[2][2]){
	ll u,v,w,x;
	u=a[0][0]*m[0][0]+a[0][1]*m[1][0];
	v=a[0][0]*m[0][1]+a[0][1]*m[1][1];
	w=a[1][0]*m[0][0]+a[1][1]*m[1][0];
	x=a[1][0]*m[0][1]+a[1][1]*m[1][1];
	a[0][0]=u;
	a[0][1]=v;
	a[1][0]=w;
	a[1][1]=x;
}
void power(ll a[2][2],ll n){
	if(n==1)
		return;
	power(a,n/2);
	ll m[2][2]={{1,1},{1,0}};
	multiply(a,a);
	if(n%2!=0)
		multiply(a,m);
}
ll fib(ll n){
	if(n<=1)
		return n;
	n--;
	ll a[2][2]={{1,1},{1,0}};
	power(a,n);
	return a[0][0];
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<fib(n)<<endl;
	}
}