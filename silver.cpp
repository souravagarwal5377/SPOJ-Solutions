#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll func(ll n){
    ll c=-1;
    while(n>0){
        n=n/2;
        c++;
    }
    return c;
}
int main(){
	ll n;
	while(1){
        sfd(n);
        if(n==0)
            break;
        ll ans=func(n);
        pf("%lld\n",ans);
	}
}
