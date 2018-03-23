#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll dp[101][101]={0};
ll a[101][101];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n,m;
    sfd(n);sfd(m);
    ll i,j;
    for(i=0;i<n;i++)
    	for(j=0;j<m;j++)
    		sfd(a[i][j]);
    ll ans=INT_MAX;
    for(i=0;i<m;i++){
    	dp[0][i]=a[0][i];
    }
    for(i=1;i<n;i++){
    	dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i][0];
    	dp[i][m-1]=min(dp[i-1][m-1],dp[i-1][m-2])+a[i][m-1];
    	for(j=1;j<m-1;j++)
    		dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+a[i][j];
    }
    for(i=0;i<m;i++){
    	if(dp[n-1][i]<ans)
    		ans=dp[n-1][i];
    }
    cout<<ans<<endl;
}
