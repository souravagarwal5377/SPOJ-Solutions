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
    ll n,m,i;
    sfd(n);sfd(m);
    vector<ll> v[n+1];
    for(i=0;i<n-1;i++){
    	ll x,y;
    	sfd(x);sfd(y);
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
}
