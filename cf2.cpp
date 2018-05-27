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
	ll s,l;
	cin>>s>>l;
	string v[s];
	ll i,j;
	for(i=0;i<s;i++)
		cin>>v[i];
	ll c[l]={0};
	for(j=0;j<l;j++){
		for(i=0;i<s;i++){
			if(v[i][j]=='1')
				c[j]++;
		}
	}
	for(i=0;i<l;i++)
		cout<<c[i]<<endl;
	for(i=0;i<s;i++){
		ll imp=0;
		for(j=0;j<l;j++){
			if(v[i][j]=='1'){
				if(c[j]==1){
					imp=1;
					break;
				}
			}
		}
		if(imp==0)
			break;
	}
	if(i==s)
		cout<<"NO\n";
	else
		cout<<"YES\n";
}