#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll parent[1000000];
ll rank[1000000]={0};
void makeset(){
	ll i;
	for(i=0;i<1000000;i++)
		parent[i]=i;
}
ll findset(ll x){
	if(parent[x]==x){
		return x;
	}
	parent[x]=findset(parent[x]);
	return parent[x];
}
ll unionset(ll a,ll b){
	ll pa=findset(a);
	ll pb=findset(b);
	if(pa==pb)
		return 1;
	if(rank[pa]>=rank[pb]){
		rank[pa]=(rank[pa]==rank[pb])?rank[pa]+1:rank[pa];
		parent[pb]=pa;
	}
	else{
		parent[pa]=pb;
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n,m;
	cin>>n>>m;
	if(n!=m+1){
		cout<<"NO\n";
		return 0;
	}
	makeset();
	while(m--){
		ll x,y;
		cin>>x>>y;
		ll ans=unionset(x,y);
		if(ans==1){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}