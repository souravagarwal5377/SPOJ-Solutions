#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main(){
	ll t;
	cin>>t;
	ll a[101];
	ll i;
	a[4]=4;
	a[5]=7;
	a[6]=12;
	for(i=7;i<=100;i++){
		a[i]=(a[i-1]-a[i-2])+(a[i-2]-a[i-3])+a[i-1];
		cout<<a[i]<<endl;
	}
	while(t--){
        ll n;
		sfd(n);
		cout<<a[n]<<endl;
	}
}
