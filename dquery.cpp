#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll a[100000];
struct node{
	set<ll> s;
};
node st[100000];
set<ll> maketree(ll l,ll u,ll pos){
	if(l==u){
		set<ll> s;
		s.insert(a[pos]);
		return s;
	}
	ll m=l+(u-l)/2;
	set<ll> left=maketree(l,m,2*pos+1);
	set<ll> right=maketree(m+1,u,2*pos+2);
	set<ll> ::iterator i;
	for(i=left.begin();i!=left.end();i++)
		right.insert((*(i)));
	return right;
}
node* query(ll l,ll u,ll ql,ll qu,ll pos){
	if(l>=ql&&u<=qu)
		return &st[pos];
	if(l>qu||ql>u){
		node * c=(node*)malloc(sizeof(node));
		return c;
	}
	ll m=l+(u-l)/2;
	node* left=query(l,m,ql,qu,2*pos+1);
	node* right=query(m+1,u,ql,qu,2*pos+2);
	set<ll> ::iterator i;
	for(i=left->s.begin();i!=left->s.end();i++)
		right->s.insert((*(i)));
	return right;	
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n;
    sfd(n);
    ll i,j,k=0;
    for(i=0;i<n;i++)
    	sfd(a[i]);
    ll q;
    sfd(q);
    maketree(0,n-1,0);
    while(q--){
    	ll u,v;
    	sfd(u);sfd(v);
    	u--;v--;
    	node* ans=query(0,n-1,u,v,0);
    	cout<<ans->s.size()<<endl;
    }
}
