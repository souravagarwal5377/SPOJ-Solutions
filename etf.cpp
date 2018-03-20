#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll a[1000001]={0};
void sieve(){
    ll i=2;
    a[0]=a[1]=1;
    for(i=2;i<=1000;i++){
        for(ll j=i*i;j<=1000000;j+=i)
            a[j]=1;
    }
}
int main()
{
    sieve();
    ll int t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        sfd(n);
        double ans=n;
        for(ll i=2;i*i<=n;i++){
            if(a[i]==0&&n%i==0){
                double mm=i;
                ans=ans*(1-1/mm);
                if(a[n/i]==0&&i!=n/i)
                {
                    double xx=mm/((double)n);
                    ans=ans*(1-xx);
                }
            }
        }
        ll aa=(ll)ans;
        if(a[n]==0){
            aa=n-1;
        }
        pf("%lld\n",aa);
    }
}
