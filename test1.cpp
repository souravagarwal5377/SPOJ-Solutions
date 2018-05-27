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
		string s;
		cin>>s;
		ll k;
		cin>>k;
		ll i,j;
		ll l = s.size();
		ll a[l+11][26];
		for(i=0;i<l;i++){
			for(j=0;j<26;j++){
				a[i][j] = 0;
			}
		}
		for(i=0;i<l;i++){
			a[i][s[i]-'a']++;
		}
		for(i=1;i<l;i++){
			for(j=0;j<26;j++){
				a[i][j]+=a[i-1][j];
			}
		}
		ll ans=0;
		for(i=0;i<l;i++){
			for(j=i;j<l;j++){
				if(i==0){
					set<ll>st;
					ll temp = 0;
					for(ll x=0;x<26;x++){
						st.insert(a[j][x]);
						if(a[j][x]){
							temp++;
						}
					}
					temp = (temp*(temp-1))/2;
					if(st.size() == 1){
						set<ll>::iterator it;
						// it = st.begin();
						if(temp>=k){
							ans++;
						}
					}
				}
				else{
					set<ll>st;
					ll temp=0;
					for(ll x=0;x<26;x++){
						st.insert(a[j][x]-a[i-1][x]);
						if((a[j][x]-a[i-1][x])){
							temp++;
						}
					}
					if(st.size()==1){
						set<ll>::iterator it;
						// it = st.begin();
						temp = (temp*(temp-1))/2;
						if(temp>=k){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}