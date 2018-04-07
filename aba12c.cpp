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
ll reverse(ll n){    /*returns the reverse of number n*/
	ll i,r=0;
	while(n>0){
		i=n%10;
		r=r*10+i;
		n/=10;
	}
	return r;
}
ll countinfactn(ll n,ll i){   /*returns the number of times a prime number*/
	ll c=0,k=i;					/* i appears in n!*/
	while(i<=n){
		c=c+(n/i);
		i=i*k;
	}
	return c;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		sfd(n);sfd(k);
		ll i,a[k+1],j,x;
		for(i=1;i<=k;i++)
			sfd(a[i]);
		ll dp[k+1][n+1];
		for(i=1;i<=k;i++){
			if(a[i]==-1)
				j=1;
			else{
				j=2;
				dp[i][1]=a[i];
			}
			for(;j<=n;j++)
				dp[i][j]=INT_MAX;
		}
		for(i=2;i<=n;i++){
			if(a[1]!=-1)
				dp[1][i]=a[1];
		}
		for(i=2;i<=k;i++){
			for(j=2;j<=n;j++){
				ll mi=dp[i][j-1];
				for(x=i-1;x>0;x--){
					mi=min(mi,dp[x][j-1]+dp[i-x][1]);
				}
				dp[i][j]=mi;
			}
		}
		if(dp[k][n]==INT_MAX)
			cout<<"-1\n";
		else
			cout<<dp[k][n]<<endl;
	}
}