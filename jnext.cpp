#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
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
		for(i=0;i<n;i++)
			sfd(a[i]);
		for(i=n-2;i>=0&&a[i]>=a[i+1];i--);
		if(i==-1){
			pf("%lld\n",i);
			continue;
		}
		ll m=i;
		ll x=INT_MAX,ppp;
		for(i=i+1;i<n;i++){
		    if(a[i]>a[m]&&a[i]<x){
		        x=a[i];
		        ppp=i;
		    }
		}
		ll rr=a[m];
		a[m]=a[ppp];
		a[ppp]=rr;
	    sort(a+m+1,a+n);
	    for(i=0;i<n;i++)
	        pf("%lld",a[i]);
		cout<<endl;
	}
}