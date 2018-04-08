#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
/*
inline void sfd(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}*/
ll dp[501][10001]={0};
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll e,f,n;
		sfd(e);sfd(f);sfd(n);
		ll i,j;
		vector<pair<ll,ll> >v;
		for(i=1;i<=n;i++){
			ll x,y;
			sfd(x);sfd(y);
            v.push_back(make_pair(y,x));
		}
        sort(v.begin(),v.end());
		for(i=1;i<f-e+1;i++){
            if(v[0].first>i)
                dp[0][i]=INT_MAX;
            else{
                if(i%v[0].first!=0)
                    dp[0][i]=INT_MAX;
                else
                    dp[0][i]=(i/v[0].first)*v[0].second;
            }
        }
        for(i=0;i<v.size();i++)
            dp[i][0]=0;
        for(i=1;i<v.size();i++){
            for(j=1;j<=f-e;j++){
                if(v[i].first>j)
                    dp[i][j]=dp[i-1][j];
                else{
                    ll xx=1;
                    dp[i][j]=dp[i-1][j];
                    while(j-xx*v[i].first>=0){
                        dp[i][j]=min(dp[i][j],dp[i-1][j-xx*v[i].first]+xx*v[i].second);
                        xx++;
                    }
                }
            }
        }
        /*for(i=0;i<v.size();i++){
            for(j=0;j<=f-e;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        ll ans=INT_MAX;
        for(i=0;i<v.size();i++){
            ans=min(ans,dp[i][f-e]);
        }
        if(ans==INT_MAX)
            cout<<"This is impossible.\n";
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;
	}
}