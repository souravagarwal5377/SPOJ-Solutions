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
struct cyl{
	ll w;
	ll ox;
	ll ni;
};
ll dp[1001][22][80]={0};
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll ox,ni,n;
		cin>>ox>>ni>>n;
		struct cyl c[n+1];
		ll i,k,j;
		for(i=1;i<=n;i++){
			cin>>c[i].ox>>c[i].ni>>c[i].w;
		}
		/*for(i=0;i<=ox;i++){
			for(j=0;j<=ni;j++)
				dp[0][i][j]=INT_MAX;
		}
		for(i=0;i<=n;i++)
			for(j=0;j<=ni;j++)
				dp[i][0][j]=0;
		for(i=0;i<=n;i++)
			for(j=0;j<=ox;j++)
				dp[i][j][0]=0;*/
		for(i=0;i<=n;i++)
			for(j=0;j<=ox;j++)
				for(k=0;k<=ni;k++)
					dp[i][j][k]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=ox;j++){
				for(k=1;k<=ni;k++){
					if(c[i].ox>j||c[i].ni>k)
						dp[i][j][k]=dp[i-1][j][k];
					else
						dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-c[i].ox][k-c[i].ni]+c[i].w);
				}
			}
		}
		cout<<dp[n][ox][ni]<<endl;
	}
}