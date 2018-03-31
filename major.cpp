#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll reverse(ll n){    /*returns the reverse of number n*/
	ll i,r=0;
	while(n>0){
		i=n%10;
		r=r*10+i;
		n/=10;
	}
	return r;
}
ll countinfactn(ll n,ll i){   /*returns the number of times a prime number*/
	ll c=0,k=i;					/* i appears in n!*/
	while(i<=n){
		c=c+(n/i);
		i=i*k;
	}
	return c;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n;
		sfd(n);
		ll i,a[n];
		map<ll,ll> m;
		for(i=0;i<n;i++){
			sfd(a[i]);
			m[a[i]]++;
		}
		ll f=0;
		for(i=-1000;i<=1000;i++){
			if(m[i]>n/2){
				f=1;
				break;
			}
		}
		if(f==1){
			cout<<"YES "<<i<<endl;
		}
		else
			cout<<"NO\n";
	}
}