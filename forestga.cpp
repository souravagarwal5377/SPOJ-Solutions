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
ll n,w,mh;
ll a[100000];
ll r[100000];
ll binary(){
	//cout<<w<<" "<<mh<<endl;
	ll l=0,u=1000000000000000000,m;
	ll ans=1000000000000000000;
	while(l<u){
		m=l+(u-l)/2;
		//cout<<l<<" "<<u<<endl;
		ll g=0,i;
		for(i=0;i<n;i++){
			if((a[i]+r[i]*m)>=mh)
				g=g+(a[i]+r[i]*m);
		}
		if(g>=w){
			ans=min(ans,m);
			u=m;
		}
		else
			l=m+1;
	}
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    ll i;
    cin>>n>>w>>mh;
	for(i=0;i<n;i++){
		cin>>a[i]>>r[i];
	}
	ll ans=binary();
	cout<<ans<<endl;
}