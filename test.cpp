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
    ll int t;   
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        sfd(n);
        ll i,a[n];
        for(i=0;i<n;i++)
            sfd(a[i]);
        ll temp,me=0,mi=0,ans=0;
        for(i=0;i<n;i++)
        {
            temp=mi;
            mi=me+a[i];
            me=max(temp,me);
            ans=max(mi,me);
        }
        cout<<ans<<endl;
    } 
}
