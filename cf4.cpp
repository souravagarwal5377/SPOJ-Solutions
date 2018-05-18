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
map<ll,ll> m;
vector<ll> ans;
ll n;
bool dfs(ll x,map<ll,ll> vis,ll c){
	c++;
	vis[x]=1;
	ans.pb(x);
	bool r=false;
	if(x%3==0&&m[x/3]>0&&vis[x/3]==0)
			r=dfs(x/3,vis,c);
	if(r==true)
		return true;
	if(m[x*2]>0&&vis[x*2]==0)
			r=dfs(2*x,vis,c);
	if(r==true)
		return true;
	if(c==n)
		return true;
	ans.pop_back();
	return false;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	sfd(n);
	ll i,a[n];
	for(i=0;i<n;i++){
		sfd(a[i]);
		m[a[i]]++;
	}
	for(i=0;i<n;i++){
		map<ll,ll> vis;
		bool res=dfs(a[i],vis,0);
		if(res==true)
			break;
		ans.clear();
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}