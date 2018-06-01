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
	ll n,m,k,i;
	cin>>n>>m>>k;
	vector<ll> v[n+1];
	for(i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	ll d[k];
	ll da[n+1]={0};
	for(i=0;i<k;i++)
		sfd(d[i]);
	ll vis[n+1]={0};
	queue<ll> q;
	ll r=-1;
	ll level[n+1]={0};
	for(i=0;i<k;i++){
		q.push(d[i]);
		vis[d[i]]=1;
		level[d[i]]=1;
		da[d[i]]=d[i];
	}
	while(!q.empty()){
		ll t=q.front();
		q.pop();
		for(i=0;i<v[t].size();i++){
			if(da[v[t][i]]==0){
				vis[v[t][i]]=1;
				q.push(v[t][i]);
				level[v[t][i]]=level[t]+1;
				da[v[t][i]]=da[t];
			}
			else{
				if(da[v[t][i]]!=0&&da[v[t][i]]!=da[t]){
					r=level[t];
					break;
				}
			}
		}
		if(r>0)
			break;
	}
	ll c=0;
	for(i=1;i<=n;i++){
		if(level[i]<=r)
			c++;
	}
	cout<<c<<endl;
}