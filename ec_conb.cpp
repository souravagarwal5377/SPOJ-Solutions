#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
#define pp pair<ll,ll>
#define pb push_back
#define inf INT_MAX;
using namespace std;
ll func(ll n){
	vector<ll> v;
	while(n>1){
		ll x=n%2;
		n/=2;
		v.pb(x);
	}
	v.pb(n);
	reverse(v.begin(),v.end());
	ll ans=0,x=1,i;
	for(i=0;i<v.size();i++){
		if(v[i]==1)
			ans=ans+x;
		x=x*2;
	}
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	sfd(n);
	ll i;
	for(i=0;i<n;i++){
		ll x;
		sfd(x);
		if(x%2==0)
			cout<<func(x)<<endl;
		else
			cout<<x<<endl;
	}
}