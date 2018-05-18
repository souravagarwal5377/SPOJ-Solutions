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
class priority{
public:
	int operator()(const pp &l,const pp &r){
		return l.second<r.second;
	}
};
int dijkstra(vector<pp> v[],ll n,ll s,ll d){// adjacency list, number of nodes, source , destination
	ll i,dis[n+1],par[n+1];
	for(i=1;i<=n;i++){
		dis[i]=inf;
		par[i]=-1;
	}
	priority_queue<pp,vector<pp>,priority> pq;
	dis[s]=0;
	pq.push(make_pair(s,0));
	while(!pq.empty()){
		ll x=pq.top().first;
		pq.pop();
		for(ll j=0;j<v[x].size();j++){
			ll y=v[x][j].first,w=v[x][j].second;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				par[y]=x;
				pq.push(make_pair(y,dis[y]));
			}
		}
	}
	return dis[d];
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n,m;
	sfd(n);sfd(m);
	vector<pp> v[10001];
	for(ll i=1;i<=10000;i++){
		if(2*i<=10000)
			v[i].push_back(make_pair(2*i,1));
		if(i-1>0)
			v[i].push_back(make_pair(i-1,1));
	}	
	ll ans=dijkstra(v,10000,n,m);
	cout<<ans<<endl;
}