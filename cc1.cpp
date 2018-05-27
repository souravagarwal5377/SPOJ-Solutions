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
ll func(ll x){
	ll i=1,s=1;
	while(i<x){
		s=s*2;
		i++;
	}
	return s;
}
ll countBits(ll number)
{      
      // log function in base 2 
      // take only integer part
      return (ll)log2(number)+1;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		if(n==1)
		{
			cout<<k<<endl;
			continue;
		}
		if(k==1){
			ll i;
			for(i=0;i<n;i++)
				cout<<"1 ";
			cout<<endl;
			continue;
		}
		ll x=countBits(k);
		ll cc=func(x);
		ll i;
		if(x>n){
			for(i=0;i<n-1;i++){
				cout<<cc<<" ";
				cc/=2;
			}
			ll s=0;
			while(cc>0){
				s+=cc;
				cc/=2;
			}
			cout<<s<<endl;
			continue;
		}
		ll kk=(n-x);
		i=0;
		if(kk%2!=0){
			if(cc==k){
				cout<<cc<<" ";
				cc/=2;
				cout<<cc<<" ";
				i=2;
			}
			else{
				cout<<cc+1<<" ";
				cc/=2;
				i=1;
			}
		}
		for(;i<x&&cc>0;i++){
			cout<<cc<<" ";
			cc/=2;
		}
		for(;i<n;i++)
			cout<<"1 ";
		cout<<endl;
	}
}