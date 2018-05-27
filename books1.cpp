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
ll binary(ll a[],ll l,ll u,ll av,ll n){
	while(l<u){
		ll m=l+(u-l)/2,cur=a[0],w=1,i;
		for(i=1;i<n;i++){
			if(a[i]>m){
				w=INT_MAX;
				break;
			}
			if(cur+a[i]<=m){
				cur+=a[i];
			}
			else{
				cur=a[i];
				w++;
			}
		}
		if(w>av)
			l=m+1;
		else
			u=m;
	}
	return u;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll i,a[n],l=INT_MAX;
		for(i=0;i<n;i++){
			sfd(a[i]);
			l=min(l,a[i]);
		}
		ll u=accumulate(a,a+n,0);
		ll chk=binary(a,l,u,m,n);
		ll cnt=1,cur=0;
		vector<ll> v;
		for(i=n-1;i>=0;i--){
			if((a[i]+cur>chk)||(m-1-cnt==i)){
				cnt++;
				v.pb(-1);v.pb(a[i]);
				cur=a[i];
			}
			else{
				cur+=a[i];
				v.pb(a[i]);
			}
		}
		reverse(v.begin(),v.end());
		for(i=0;i<v.size();i++){
			if(v[i]==-1)
				cout<<"/ ";
			else
				cout<<v[i]<<" ";
		}
		cout<<endl;
	}
}