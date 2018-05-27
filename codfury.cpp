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
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll p,m;
		cin>>p>>m;
		ll i,a[p];
		for(i=0;i<p;i++)
			cin>>a[i];
		for(i=0;i<n&&s<m;i++){
			s+=a[i];
		}
		c=i;
		if(s>m){
			s=s-a[i-1];
			c--;
		}
		for()
	}
}