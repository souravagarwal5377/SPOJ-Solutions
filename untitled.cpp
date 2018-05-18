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
	ll n,m;
	sfd(n);sfd(m);
	ll s[n],e[n],d[n],i;
	map<ll,ll> mp;
	vector<pair<ll,pair<ll,ll> > > v;
	for(i=0;i<m;i++){
		sfd(s[i]);sfd(e[i]);sfd(d[i]);
		v.pb(make_pair(s[i],make_pair(d[i],e[i])));
		mp[e[i]]++;
	}
	ll j=0;
	sort(v.begin(),v.end());
	vector<ll> ans;
	j=0;
	for(i=1;i<=n;i++){
		if(mp[i]==1)
			ans.pb(m+1);
		else{
			for(;j<n;j++){
				
			}
		}
	}
}