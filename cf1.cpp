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
	map<string,string> m;
	m["purple"]="Power";
	m["green"]="Time";
	m["blue"]="Space";
	m["orange"]="Soul";
	m["red"]="Reality";
	m["yellow"]="Mind";
	ll n;
	cin>>n;
	map<string,ll> c;
	c["purple"]=0;
	c["green"]=0;
	c["blue"]=0;
	c["orange"]=0;
	c["red"]=0;
	c["yellow"]=0;
	vector<string> v;
	v.pb("purple");
	v.pb("green");
	v.pb("blue");
	v.pb("orange");
	v.pb("red");
	v.pb("yellow");
	if(n==6)
		cout<<"0\n";
	else{
		cout<<6-n<<endl;
		for(ll i=0;i<n;i++){
			string hh;
			v.pb(hh);
			cin>>hh;
			c[hh]=1;
		}
		for(ll i=0;i<6;i++){
			if(c[v[i]]==0)
				cout<<m[v[i]]<<endl;
		}
	}
}