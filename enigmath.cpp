#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    ll int t;
    scanf("%lld",&t);
    while(t--)
    {
        ll a,b;
        sfd(a);sfd(b);
        ll x=max(a,b);
        ll y=min(a,b);
        ll g=gcd(x,y);
        g=(a*b)/g;
        x=g/a;
        y=g/b;
        cout<<x<<" "<<y<<endl;
    }
}
