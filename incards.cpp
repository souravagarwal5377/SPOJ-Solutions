#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
#define pp pair<ll,ll>
#define pb push_back
#define inf 1e9;
using namespace std;
ll dijkstra(vector<pp> v[],ll n,ll m,ll s){
	ll vis[n+1]={0};
	priority_queue<pp,vector<pp>, greater<pp> > pq;
	pq.push(make_pair(0,s));
	vis[s]=1;
	ll dist[n+1],i;
	for(i=2;i<=n;i++)
		dist[i]=inf;
	dist[1]=0;
	while(!pq.empty()){
		ll x=pq.top().second;
		vis[x]=1;
		pq.pop();
		for(i=0;i<v[x].size();i++){
			if(!vis[v[x][i].second]&&(dist[x]+v[x][i].first<dist[v[x][i].second])){
				dist[v[x][i].second]=dist[x]+v[x][i].first;
				pq.push(make_pair(dist[x]+v[x][i].first,v[x][i].second));
			}
		}
	}
	ll sum=0;
	for(i=2;i<=n;i++)
		sum+=dist[i];
	return sum;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    ll t;
    sfd(t);
    while(t--){
		ll n,m;
		sfd(n);sfd(m);
		vector<pp> v[n+1];
		ll i;
		for(i=0;i<m;i++){
			ll x,y,z;
			sfd(x);sfd(y);sfd(z);
			v[x].pb(make_pair(z,y));
		}
		ll oj=dijkstra(v,n,m,1);
		vector<pp> cv[n+1];
		for(i=1;i<=n;i++){
			for(ll j=0;j<v[i].size();j++){
				cv[v[i][j].second].pb(make_pair(v[i][j].first,i));
			}
		}
		ll rj=dijkstra(cv,n,m,1);
		cout<<rj+oj<<endl;
	}
}