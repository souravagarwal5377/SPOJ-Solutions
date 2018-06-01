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
	ll t;
	cin>>t;
	while(t--){
		ll n,m,a,b,i;
		cin>>n>>m>>a>>b;
		vector<pair<ll,ll> > v[n+1];
		for(i=0;i<m;i++){
			ll x,y,z;
			cin>>x>>y>>z;
			v[x].pb(make_pair(z,y));
			v[y].pb(make_pair(z,x));
		}
		ll dis[n+1];
		for(i=1;i<=n;i++)
			dis[i]=INT_MAX;
		priority_queue<pp,vector<pp>,greater<pp> > pq;
		pq.push(make_pair(0,a));
		dis[a]=0;
		while(!pq.empty()){
			ll x=pq.top().second;
			pq.pop();
			for(i=0;i<v[x].size();i++){
				if(dis[v[x][i].second]>dis[x]+v[x][i].first){
					dis[v[x][i].second]=dis[x]+v[x][i].first;
					pq.push(make_pair(dis[v[x][i].second],v[x][i].second));
				}
			}
		}
		if(dis[b]==INT_MAX)
			cout<<"NONE\n";
		else
			cout<<dis[b]<<endl; 
	}
}