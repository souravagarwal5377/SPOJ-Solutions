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
string ans;
void func(ll x){
	pair<string,ll> p=make_pair("1",1);
	list<pair<string,ll> > q;
	q.push_back(p);
	while(!q.empty()){
		string w=q.front().first;
		ll r=q.front().second;
		if(r%x==0){
			ans=w;
			return;
		}
		q.pop_front();
		r=r%x;
		q.push_back(make_pair(w+"0",r*10));
		q.push_back(make_pair(w+"1",r*10+1));
	}
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll i;
	ll t;
	sfd(t);
	while(t--){
		ll n;
		sfd(n);
		func(n);
		cout<<ans<<endl;
	}
}