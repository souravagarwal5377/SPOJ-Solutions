#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
	    ll n,p;
		sfd(n);
		sfd(p);
		vector<ll> v[n];
		ll i;
		for(i=0;i<p;i++){
		    ll x,y;
			sfd(x);sfd(y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ll vis[n]={0};
		queue<ll> q;
		ll c=0;
		for(i=0;i<n;i++){
			if(vis[i]==1)
				continue;
			q.push(i);
			vis[i]=1;
			c++;
			while(!q.empty()){
				ll u=q.front();
				q.pop();
				for(ll j=0;j<v[u].size();j++){
					if(vis[v[u][j]]==0){
						q.push(v[u][j]);
						vis[v[u][j]]=1;
					}
				}
			}
		}
		pf("%lld\n",c);
	}
}