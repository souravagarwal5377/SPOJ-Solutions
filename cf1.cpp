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
	string s;
	cin>>s;
	ll i;
	for(i=1;i<s.length()-1;i++){
		if(s[i]=='A'&&(s[i-1]=='B'||s[i+1]=='B')&&(s[i-1]=='C'||s[i+1]=='C')){
			cout<<"Yes\n";
			return 0;
		}
		else if(s[i]=='B'&&(s[i-1]=='A'||s[i+1]=='A')&&(s[i-1]=='C'||s[i+1]=='C')){
			cout<<"Yes\n";
			return 0;
		}
		else if(s[i]=='C'&&(s[i-1]=='B'||s[i+1]=='B')&&(s[i-1]=='A'||s[i+1]=='A')){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
}