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
		ll n,k;
		cin>>n>>k;
		ll i,a[n];
		for(i=0;i<n;i++)
			sfd(a[i]);
		ll ans=0,mc=0,s=0,c=0,sp=0;
		for(i=0;i<n;i++){
			if(a[i]+s<=k){
				if(s==0)
					sp=i;
				s+=a[i];
				c++;
				if(c>mc||(c==mc&&s<ans)){
					ans=s;
					mc=c;
				}
			}
			else{
				s+=a[i];
				c++;
				while(sp<=i &&s>k){
					c--;
					s-=a[sp];
					sp++;
				}
				if(c>mc||(c==mc&&s<ans)){
					ans=s;
					mc=c;
				}
				//cout<<s<<" "<<c<<endl;
			}
		}
		cout<<ans<<" "<<mc<<endl;
	}
}