#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll dc(ll n){
	ll d=0;
	if(n==0)
		return 1;
	while(n>0){
		d++;
		n/=10;
	}
	return d;
}
ll power(ll a,ll b){
	ll ans=1;
	for(ll i=0;i<b;i++)
		ans=ans*a;
	return ans;
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
		for(i=0;i<n;i++)
			sfd(a[i]);
		if(n==1){
			cout<<"YES\n";
			continue;
		}
		ll d[n];
		for(i=0;i<n;i++){
			d[i]=dc(a[i]);
		}
		vector<ll> v[11];
		ll fl=0;
		for(i=0;i<n;i++){
			ll x=d[i];
			ll y=power(10,x-1);
			for(ll j=1;j<x;j++){
				ll temp=a[i]/y;
				v[j].push_back(temp);
				y/=10;
			}
		}
		for(i=1;i<=10;i++)
			sort(v[i].begin(),v[i].end());
		/*for(i=1;i<=10;i++){
			for(ll j=0;j<v[i].size();j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}*/
		for(i=0;i<n;i++){
			ll x=d[i];
			bool ans=binary_search(v[x].begin(),v[x].end(),a[i]);
			if(ans==true){
				fl=1;
				break;
			}
		}
		if(fl==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}