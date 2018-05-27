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
	ll n,k,l;
	cin>>n>>k>>l;
	ll i,a[n*k];
	for(i=0;i<n*k;i++){
		sfd(a[i]);
	}
	sort(a,a+(n*k));
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	ll cd=0;
	for(i=1;i<n*k&&cd<=l;i++){
		cd=cd+a[i]-a[i-1];
	}
	if(cd>l)
		i-=2;
	if(i==n*k)
		i--;
	//cout<<i<<endl;
	ll j,ans=a[0],c=1;
	for(j=k;c<n&&j<=i;j++){
		c++;
		ans+=a[j];
	}
	if(c==n&&j>=0)
		cout<<ans<<endl;
	else
		cout<<"0\n";
	return 0;
}