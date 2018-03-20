#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
struct node{
	ll m;
	ll sm;
};
node st[500000]={0};
void maketree(ll* a,ll l,ll u,ll pos){
	if(l==u){
		st[pos].m=a[l];
		st[pos].sm=-100;
		return;
	}
	ll mid=l+(u-l)/2;
	maketree(a,l,mid,2*pos+1);
	maketree(a,mid+1,u,2*pos+2);
	st[pos].m=max(st[2*pos+1].m,st[2*pos+2].m);
	ll tt=min(st[2*pos+1].m,st[2*pos+2].m);
	st[pos].sm=max(max(st[2*pos+1].sm,st[2*pos+2].sm),tt);
}
void update(ll ql,ll qu,ll l,ll u,ll v,ll pos){
	if(l>=ql&&u<=qu){
		st[pos].m=v;
		st[pos].sm=-1;
		return;
	}
	if(l>qu||ql>u)
		return;
	ll mid=l+(u-l)/2;
	update(ql,qu,l,mid,v,2*pos+1);
	update(ql,qu,mid+1,u,v,2*pos+2);
	st[pos].m=max(st[2*pos+1].m,st[2*pos+2].m);
	ll tt=min(st[2*pos+1].m,st[2*pos+2].m);
	st[pos].sm=max(max(st[2*pos+1].sm,st[2*pos+2].sm),tt);
}
node* query(ll ql,ll qu,ll l,ll u,ll pos){
	if(l>=ql&&u<=qu){
		return &st[pos];
	}
	if(l>qu||u<ql){
		node * nn=(node*)malloc(sizeof(node));
		nn->m=nn->sm=-1;
		return nn;
	}
	ll mid=l+(u-l)/2;
	node* left=query(ql,qu,l,mid,2*pos+1);
	node* right=query(ql,qu,mid+1,u,2*pos+2);
	node* tt=(node*)malloc(sizeof(node));
	tt->m=max(left->m,right->m);
	ll ttt=min(left->m,right->m);
	tt->sm=max(max(left->sm,right->sm),ttt);
	return tt;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	sfd(n);
	ll i,a[n];
	for(i=0;i<n;i++)
		sfd(a[i]);
	maketree(a,0,n-1,0);
	ll q;
	sfd(q);
	while(q--){
		char c;
		cin>>c;
		ll x,y;
		sfd(x);sfd(y);
		if(c=='U'){
			x--;
			update(x,x,0,n-1,y,0);
		}
		else if(c=='Q'){
			x--;y--;
			node* ans=query(x,y,0,n-1,0);
			ll p=ans->m+ans->sm;
			pf("%lld\n",p);
		}
	}
}