#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll dp[2001][2001];
ll func(ll *a,ll s,ll e,ll t){
	if(s>e)
		return 0;
	if(dp[s+1][e]==-1)
		dp[s+1][e]=func(a,s+1,e,t+1);
	if(dp[s][e-1]==-1)
		dp[s][e-1]=func(a,s,e-1,t+1);
	dp[s][e]=max(a[s]*t+dp[s+1][e],a[e]*t+dp[s][e-1]);
	return dp[s][e];
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	sfd(n);
	ll i,a[n],j;
	for(i=0;i<n;i++)
		sfd(a[i]);
	for(i=0;i<2001;i++)
		for(j=0;j<2001;j++)
			dp[i][j]=-1;
	ll ans=func(a,0,n-1,1);
	cout<<ans<<endl;
}