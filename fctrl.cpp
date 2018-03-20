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
ll countinfactn(ll n,ll i){
	ll c=0,k=i;
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
		cin>>n;
		ll c2=countinfactn(n,2),c5=countinfactn(n,5);
		cout<<min(c2,c5)<<endl;
	}
}