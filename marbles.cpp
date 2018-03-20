#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll prime[1000001]={0};
ll countinfactn(ll n,ll i){   /*returns the number of times a prime number*/
	ll c=0,k=i;					/* i appears in n!*/
	while(i<=n){
		c=c+(n/i);
		i=i*k;
	}
	return c;
}
void sie(){
    ll i,j;
    prime[0]=prime[1]=1;
    for(i=2;i<=1000;i++){
        for(j=i*i;j<=1000000;j+=i)
            prime[j]=1;
    }
}
int main()
{
    ll int t;
    sie();
    scanf("%lld",&t);
    while(t--)
    {
        ll n,r;
        sfd(n);sfd(r);
        ll j=1,ans=1,l=n-r;

    }
}

