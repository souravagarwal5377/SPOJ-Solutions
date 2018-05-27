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
		ll n,m,p,i;
		cin>>p>>n>>m;
		vector<pair<ll,ll> > v[n+1];
		for(i=0;i<m;i++){
			ll x,y,w;
			cin>>x>>y>>w;
			v[x].pb(make_pair(w,y));
			v[y].pb(make_pair(w,x));
		}
		priority_queue< pp, vector<pp> , greater<pp> > pq;
		vector<ll> par(n+1,-1);
		vector<ll> d(n+1,INT_MAX);
		vector<ll> vis(n+1,0);
		pq.push(make_pair(0,1));
		d[1]=0;
		ll cost=0;
		while(!pq.empty()){
			pair<ll,ll> tp=pq.top();
			pq.pop();
			ll wt=tp.first;
			ll node=tp.second;
			if(vis[node]==0){
				vis[node]=1;
				cost+=d[node];
			}
			for(i=0;i<v[node].size();i++){
				if(vis[v[node][i].second]==0&&d[v[node][i].second]>v[node][i].first){
					d[v[node][i].second]=v[node][i].first;
					par[v[node][i].second]=node;
					pq.push(make_pair(v[node][i].first,v[node][i].second));
				}
			}
		}
		cout<<cost*p<<endl;
	}
}