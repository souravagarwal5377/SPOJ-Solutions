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
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	sfd(n);
	ll i,x;
	vector<ll> v;
	ll m=n/2;
	for(i=0;i<m;i++){
		sfd(x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	ll a=0,b=0;
	x=n-1;
	for(i=v.size()-1;i>=0&&x>0;i--){
		b=b+abs(v[i]-x);
		x-=2;
	}
	x=n;
	for(i=v.size()-1;i>=0&&x>0;i--){
		a=a+abs(v[i]-x);
		x-=2;
	}
	ll ans=min(a,b);
	cout<<ans<<endl;
}