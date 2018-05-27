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
ll p[1000]={0};
vector<ll> v;
void sieve(){
	ll i;
	p[0]=p[1]=1;
	for(i=2;i<=1000;i++){
		if(p[i]==1)
			continue;
		v.pb(i);
		for(ll j=i*i;j<=1000;j+=i)
			p[j]=1;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    sieve();
    ll i;
    vector<ll> ans;
    cout<<v.size()<<endl;
    for(i=0;i<50;i++){
    	for(ll j=i+1;j<50;j++){
    		for(ll k=j+1;k<50;k++)
    			ans.pb(v[i]*v[j]*v[k]);
    	}
    } 
    for(i=50;i<v.size();i++){
    	ans.pb(2*3*v[i]);
    }
    sort(ans.begin(),ans.end());
	ll t;
	cin>>t;
	while(t--){
		ll n;
		sfd(n);
		cout<<ans[n-1]<<endl;
	}
}