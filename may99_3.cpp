#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll x,y,z;
		sfd(x);sfd(y);sfd(z);
		ll g=__gcd(x,y);
		if(z%g==0&&(z<=x||z<=y))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}