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
ll n;
vector<pp> v[10001];
void update(ll a,ll b,ll w){
	ll l=0,u=v[a].size()-1,m;
	while(l<=u){
		m=l+(u-l)/2;
		if(v[a][m].first==b){
			v[a][m].second=w;
			break;
		}
		if(v[a][m].first>b)
			u=m-1;
		else
			l=m+1;
	}
	l=0,u=v[b].size()-1;
	while(l<=u){
		m=l+(u-l)/2;
		if(v[b][m].first==a){
			v[b][m].second=w;
			break;
		}
		if(v[b][m].first>a)
			u=m-1;
		else
			l=m+1;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll i;
		sfd(n);
		map<ll,pp> m;
		for(i=1;i<=10000;i++)
			v[i].resize(0);
		for(i=1;i<n;i++){
			ll x,y,z;
			cin>>x>>y>>z;
			v[x].pb(make_pair(y,z));
			v[y].pb(make_pair(x,z));
			m[i]=make_pair(x,y);
		}
		for(i=1;i<=n;i++)
			sort(v[i].begin(),v[i].end());
		while(1){
			string s;
			cin>>s;
			if(s[0]=='D')
				break;
			if(s[0]=='C'){
				ll x,y;
				cin>>x>>y;
				update(m[x].first,m[x].second,y);
			}
			if(s[0]=='Q'){
				
			}
		}
	}
}