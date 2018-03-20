#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll reverse(ll n){
	ll i,r=0;
	while(n>0){
		i=n%10;
		r=r*10+i;
		n/=10;
	}
	return r;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		a=reverse(a);
		b=reverse(b);
		ll ans=reverse(a+b);
		cout<<ans<<endl;
	}
}