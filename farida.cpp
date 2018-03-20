#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main()
{
    ll int t,j=1;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        sfd(n);
        ll i,a[n];
        for(i=0;i<n;i++)
            sfd(a[i]);
        if(n==0)
        {
            cout<<"Case "<<j<<": "<<"0\n";
            j++;
            continue;
        }
        if(n==1){
            cout<<"Case "<<j<<": "<<a[0]<<endl;
            j++;
            continue;
        }
        ll ans=0,mi=0,me=0;
        for(i=0;i<n;i++){
            ll temp=mi;
            mi=me+a[i];
            me=max(ans,temp);
            ans=max(mi,me);
        }
        cout<<"Case "<<j<<": "<<ans<<endl;
        j++;
    }
}

