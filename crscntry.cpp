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
ll lcs(vector<ll>a,vector<ll> b){
	ll dp[2001][2001]={0};
	ll i,j;
	for(i=1;i<a.size();i++){
		for(j=1;j<b.size();j++){
			if(a[i]==b[j])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[a.size()-1][b.size()-1];
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		vector<ll> g;
		g.pb(-1);
		while(1){
			ll x;
			sfd(x);
			if(x==0)
				break;
			g.pb(x);
		}
		ll m=0;
		while(1){
			vector<ll> v;
			v.pb(-2);
			ll cnt=0;
			while(1){
				ll x;
				sfd(x);
				if(x==0)
					break;
				cnt++;
				v.pb(x);
			}
			if(cnt==0)
				break;
			ll chk=lcs(v,g);
			if(chk>m)
				m=chk;
		}
		cout<<m<<endl;
	}
}