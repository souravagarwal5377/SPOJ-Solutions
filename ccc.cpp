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
ll cnt(ll n){
	ll i=1,s=0;
	for(;i*i<=n;i++){
		if(n%i==0&&i*i!=n)
			s+=2;
		else if(n%i==0)
			s++;
	}
	return s;
}
ll ans[1000001];
ll func(ll x){
	if(ans[x]==-1){
		if(x%2==0){
			ans[x]=func(x/2)+1;
			return ans[x];
		}
		else
			ans[x]=
	}
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    for(i=0;i<=1000000;i++)
    	ans[i]=-1; 
    ans[1]=1;
    for(i=2;i<=1000000;i=i*2){
    	ans[i]=ans[i/2]+1;
    }
    for(i=3;i<=1000000;i++){
    	if(ans[i]==-1)
    		ans[i]=func(i);
    }
}