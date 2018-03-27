#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll a[65][10]={0};
    ll i,j;
    for(i=0;i<=9;i++)
    	a[1][i]=1;
    for(i=2;i<=64;i++){
    	for(j=0;j<10;j++){
    		for(ll k=0;k<=j;k++)
    			a[i][j]+=a[i-1][k];
    	}
    }
    ll int t;   
    scanf("%lld",&t);
    while(t--)
    {
    	ll x,n;
		sfd(x);sfd(n);   
		cout<<x<<" ";
		ll s=0;
		for(i=0;i<=9;i++){
			s+=a[n][i];
		}     
		cout<<s<<endl;
    } 
}
