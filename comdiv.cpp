#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll fact(ll n){
	ll c=0,i=1;
	while(i*i<=n){
		ll d=n/i;
		if(n%i==0){
			c++;
			if(i!=d)
				c++;
		}
	}
	return c;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		sfd(a);sfd(b);
		ll g=__gcd(a,b);
		ll n=fact(g);
		pf("%lld\n",n);
	}
}