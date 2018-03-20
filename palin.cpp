#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ispalin(ll *n,ll start){
	ll i=start,j=1000000;
	for(;i<start+(1000000-start+1)/2;i++,j--){
		if(n[i]!=n[j])
			return 0;
		//cout<<n[i]<<" "<<n[j]<<endl;
	}
	return 1;
}
ll add(ll *n,ll x){
	ll i=1000000;
	n[i]++;
	ll c=n[i]/10;
	n[i]%=10;
	i--;
	while(i>=0&&c>0){
		n[i]=n[i]+c;
		c=n[i]/10;
		n[i]=n[i]%10;
		i--;
	}
	if(i<x)
		return i+1;
	return x;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll l=s.length();
		ll n[1000001]={0},j=1000000;
		for(ll i=l-1;i>=0;i--)
			n[j--]=s[i]-'0';
		ll start=j+1;
		while(1){
			start=add(&n[0],start);
			//cout<<start<<endl;
			ll ans=ispalin(n,start);
			if(ans==1){
				ll p;
				for(p=start;p<=1000000;p++)
					cout<<n[p];
				break;
			}
		}
		cout<<endl;
	}
}