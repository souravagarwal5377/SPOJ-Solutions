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
	ll t,i,j;
	cin>>t;
	ll dp[1008][1008]={0};
	for(i=1;i<=1007;i++)
		for(j=1;j<=1007;j++)
			dp[i][j]=1;
	for(i=1;i<=1007;i++){
		for(j=1;j<=1007;j++){
			if(i-2>0&&j-8>0){
				dp[i][j]=2+dp[i-2][j-8];
			}
			if(i-17>0){
				dp[i][j]=max(dp[i][j],2+dp[i-17][j+7]);
			}
		}
	}
	while(t--){
		ll h,a;
		cin>>h>>a;
		cout<<dp[h][a]<<endl;
	}
}