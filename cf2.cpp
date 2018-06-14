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
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	ll i;
	for(i=0;i<s.length()-p;i++){
		if(s[i]=='.'){
			if(s[i+p]=='.'){
				s[i]='1';
				s[i+p]='0';
			}
			else if(s[i+p]=='0')
				s[i]='1';
			else
				s[i]='0';
		}
		else if(s[i]=='1'){
			if(s[i+p]=='.')
				s[i+p]='0';
		}
		else{
			if(s[i+p]=='.')
				s[i+p]='1';
		}
	}
	for(i=0;i<s.length();i++){
		if(s[i]=='.')
			s[i]='1';
	}
	for(i=0;i<s.length()-p;i++){
		if(s[i]!=s[i+p]){
			cout<<s<<endl;
			return 0;
		}
	}
		cout<<"No\n";
}