#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
#define pp pair<ll,ll>
#define pb push_back
#define inf INT_MAX;
using namespace std;
ll sqrot(ll n){
	ll l=0,u=1000000,r=0;
	while(l<=u){
		ll m=l+(u-l)/2;
		//cout<<m<<endl;
		if(m*m==n)
			return m;
		if(m*m<n){
			r=m;
			l=m+1;
		}
		else
			u=m-1;
	}
	return r;
}
ll a[1000001]={0};
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	sfd(t);
	ll i;
	//pf("%lld\n",sqrot(1000000000000));
	for(i=0;i<=1000000;i++)
		a[i]=i*i;
	while(t--){
		ll n;
		sfd(n);
		ll l=0,u=sqrot(n);
		ll f=0;
		while(l<=u){
			if(a[l]+a[u]==n){
				f=1;
				cout<<"Yes\n";
				break;
			}
			if(a[l]+a[u]>n)
				u--;
			else
				l++;
		}
		if(f==0)
			cout<<"No\n";
	}
}