#include<bits/stdc++.h>
#define ll long long
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
ll countinfactn(ll n,ll i){   /*returns the number of times a prime number i appears in n!*/
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
	ll n;
	while(1){
		cin>>n;
		if(n==-1)
			break;
		ll a[n],i,s=0,ans=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
		}
		if(s%n!=0){
			cout<<"-1\n";
			continue;
		}
		s=s/n;
		for(i=0;i<n;i++){
			if(a[i]>s)
				ans+=a[i]-s;
		}
		cout<<ans<<endl;
	}	
}