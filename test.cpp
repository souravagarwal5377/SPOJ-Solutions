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
ll dijkstra(vector<pp> v[],ll n,ll s,ll d){// adjacency list, number of nodes, source , destination
	ll i,dis[n+1];
	for(i=1;i<=n;i++)
		dis[i]=inf;
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
	ll t;
	cin>>t;
	while(t--){
		ll n,e,i,x,y,z;
		sfd(n);sfd(e);
		vector<pp> v[n+1];
		for(i=0;i<e;i++){
			sfd(x);sfd(y);sfd(z);
			v[x].pb(make_pair(y,z));
		}
		ll s,d;
		sfd(s);sfd(d);
		ll ans=dijkstra(v,n,s,d);
		if(ans==INT_MAX)
			cout<<"NO\n";
		else
			cout<<ans<<endl;
	}
}