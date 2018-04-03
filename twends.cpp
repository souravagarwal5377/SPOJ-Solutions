#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll dp[1005][1005];
ll func(ll a[],ll s,ll e){
	ll left,right;
	if(dp[s][e]!=-1)
		return dp[s][e];
	if(s>e)
		return 0;
	if(a[s+1]>=a[e])
		left=a[s]+func(a,s+2,e);
	else
		left=a[s]+func(a,s+1,e-1);
	if(a[e-1]>a[s])
		right=func(a,s,e-2)+a[e];
	else
		right=func(a,s+1,e-1)+a[e];
	dp[s][e]=max(left,right);
	return dp[s][e];
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    ll x=1; 
	while(1){
		ll n;
		sfd(n);
		if(n==0)
			break;
		ll i,a[n];
		for(i=0;i<1005;i++)
			for(ll j=0;j<1005;j++)
				dp[i][j]=-1;
		ll s=0;
		for(i=0;i<n;i++){
			sfd(a[i]);
			s+=a[i];
		}
		ll ans=func(a,0,n-1);
		printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",x,ans-(s-ans));
		x++;
	}
}