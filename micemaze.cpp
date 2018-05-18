#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
void dfs(){
    if(vis)
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll int t;   
    scanf("%lld",&t);
    ll n,e,t,m,i;
    sfd(n);sfd(e);sfd(t);sfd(m);
    vector<pair<ll,ll> > v[n+1];
    for(i=0;i<m;i++){
        ll x,y,w;
        sfd(x);sfd(y);sfd(w);
        v[x].push_back(make_pair(y,w));
    }
    ll s=0,j;
        
}
