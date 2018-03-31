#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<ll> adj[10];
    adj[0].push_back(7);
    adj[1].push_back(2);adj[1].push_back(4);
    adj[2].push_back(1);adj[2].push_back(5);adj[2].push_back(3);
    adj[3].push_back(2);adj[3].push_back(6);
    adj[4].push_back(1);adj[4].push_back(5);adj[4].push_back(7);
    adj[5].push_back(2);adj[5].push_back(4);
    adj[5].push_back(6);adj[5].push_back(8);
    adj[6].push_back(5);adj[6].push_back(9);adj[6].push_back(3);
    adj[7].push_back(0);adj[7].push_back(4);adj[7].push_back(8);
    adj[8].push_back(5);adj[8].push_back(7);adj[8].push_back(9);
    adj[9].push_back(6);adj[9].push_back(8);
    ll dp[100001][10]={0};
    ll i,j,k;
    for(i=0;i<10;i++){
    	dp[1][i]=1; 
    	dp[0][i]=0;
    }
    for(i=2;i<=100000;i++){
    	for(j=0;j<10;j++){
    		for(k=0;k<adj[j].size();k++){
    			dp[i][j]=(dp[i][j]+dp[i-1][adj[j][k]])%M;
    		}
    	}
    }
	ll t;
	cin>>t;
	while(t--){
		ll n;
		sfd(n);
		ll s=0;
		for(i=0;i<10;i++)
			s=(s+dp[n][i])%M;
		cout<<s<<endl;
	}
}