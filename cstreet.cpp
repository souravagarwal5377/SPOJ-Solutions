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
struct edge{
	ll s;
	ll d;
	ll w;
};
bool my(edge l,edge r){
	if(l.w!=r.w)
		return l.w<r.w;
	return l.s<r.s;
}
ll p[1001];
ll r[1001];
void makeset(ll n){
	ll i;
	for(i=1;i<=n;i++){
		p[i]=i;
		r[i]=0;
	}
}
ll findset(ll x){
	if(p[x]==x)
		return x;
	p[x]=findset(p[x]);
	return p[x];
}
ll unionset(ll x,ll y){
	ll px=findset(x);
	ll py=findset(y);
	if(px==py)
		return -1;
	if(r[px]<=r[py]){
		p[px]=py;
		r[py]=(r[px]==r[py])?r[py]+1:r[py];
	}
	else{
		p[py]=px;
	}
	return 1;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll cost,n,m,i;
		sfd(cost);
		//cout<<cost<<endl;
		sfd(n);sfd(m);
		struct edge e[m];
		for(i=0;i<m;i++){
			sfd(e[i].s);sfd(e[i].d);sfd(e[i].w);
		}
		sort(e,e+m,my);
		// for(i=0;i<m;i++)
		// 	cout<<e[i].s<<" "<<e[i].d<<" "<<e[i].w<<endl;
		makeset(n);
		ll ans=0;
		for(i=0;i<m;i++){
			ll chk=unionset(e[i].s,e[i].d);
			//cout<<chk<<endl;
			if(chk==1)
				ans+=e[i].w;
		}
		pf("%lld\n",ans*cost);
	}
}