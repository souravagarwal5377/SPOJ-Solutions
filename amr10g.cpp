#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main()
{
    ll int t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,k;
        sfd(n);sfd(k);
        ll i,a[n];
        for(i=0;i<n;i++)
            sfd(a[i]);
        sort(a,a+n);
        ll m=a[k-1]-a[0],j=1;
        for(i=k;i<n;i++,j++){
            if(a[i]-a[j]<m){
                m=a[i]-a[j];
            }
        }
        pf("%lld\n",m);
    }
}

