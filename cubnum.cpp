#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll cr[100001]={0};
ll cubrt(){
	ll i;
	cr[0]=0;
	cr[1]=1;
	for(i=2;i<=100000;i++){
		ll x=cr[i-1]+1;
		if(x*x*x==i)
			cr[i]=x;
		else
			cr[i]=cr[i-1];
	}
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	ll dp[100001]={0};
	dp[1]=1;
	dp[2]=2;
	cubrt();
	for(ll i=3;i<100001;i++){
		ll m=INT_MAX,x=cr[i];
		for(ll j=1;j<=cr[i];j++){
			m=min(m,dp[(j*j*j)]+dp[i-(j*j*j)]);
		}
		if(cr[i]*cr[i]*cr[i]==i)
			m=1;	
		dp[i]=m;
	}
	ll c=0;
	while(sfd(n)!=EOF){
		c++;
		pf("Case #%lld: %lld\n",c,dp[n]);
	}
}