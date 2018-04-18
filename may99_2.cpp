#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
using namespace std;
char s[10000000];
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n,l=0;
		sfd(n);
		map<ll,char> m;
		//cout<<n<<" "<<c<<endl;
		m[1]='m';m[2]='a';m[3]='n';m[4]='k';m[0]='u';
		ll d;
		while(n>0){
			d=n%5;
			s[l++]=m[d];
			if(n%5==0)
				n=n/5-1;
			else
				n/=5;
		}
		for(ll i=l-1;i>=0;i--)
			cout<<s[i];
		cout<<endl;
	}
}