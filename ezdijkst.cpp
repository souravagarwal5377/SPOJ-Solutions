#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
#define pp pair<ll,ll>
#define pb push_back
using namespace std;
class priority{
public:
	int operator()(const pp &l,const pp &r){
		return l.second<r.second;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n,e,i,x,y,z;
		sfd(n);sfd(e);
		vector<pp> v[n+1];
		for(i=0;i<e;i++){
			sfd(x);sfd(y);sfd(z);
			v[x].pb(make_pair(y,z));
		}
		ll s,d;
		sfd(s);sfd(d);
		ll dis[n+1];
		for(i=1;i<=n;i++)
			dis[i]=INT_MAX;
		dis[s]=0;
		priority_queue<pp,vector<pp>,priority> pq;
		pq.push(make_pair(s,0));
		while(!pq.empty()){
			pp temp=pq.top();
			pq.pop();
			ll xx=temp.first;
			for(ll j=0;j<v[xx].size();j++){
				x=v[xx][j].first;
				y=v[xx][j].second;
				if(dis[x]>dis[xx]+y){
					dis[x]=dis[xx]+y;
					pq.push(make_pair(x,dis[x]));
				}
			}
		}
		if(dis[d]==INT_MAX)
			cout<<"NO\n";
		else
			cout<<dis[d]<<endl;
	}
}