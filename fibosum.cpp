#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
using namespace std;
//Considers 0th term to be 0 and 1st and 2nd terms to be 1
void multiply(ll a[2][2],ll m[2][2]){
	ll u,v,w,x;
	u=((a[0][0]*m[0][0])%M+(a[0][1]*m[1][0])%M)%M;
	v=((a[0][0]*m[0][1])%M+(a[0][1]*m[1][1])%M)%M;
	w=((a[1][0]*m[0][0])%M+(a[1][1]*m[1][0])%M)%M;
	x=((a[1][0]*m[0][1])%M+(a[1][1]*m[1][1])%M)%M;
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
		ll a,b;
		sfd(a);sfd(b);
		ll x=fib(a+1)-1;
		ll y=fib(b+2)-1;
		ll ans=(y-x+M)%M;
		cout<<ans<<endl;
	}
}