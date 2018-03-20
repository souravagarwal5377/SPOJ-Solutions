#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
struct node{
    ll ls;
    ll rs;
    ll ms;
    ll sum;
};
struct node st[200000];
void maketree(ll *a,ll l,ll u,ll pos){
    if(l==u){
        st[pos].ls=st[pos].rs=st[pos].ms=st[pos].sum=a[l];
        return;
    }
    ll m=l+(u-l)/2;
    maketree(a,l,m,2*pos+1);
    maketree(a,m+1,u,2*pos+2);
    st[pos].sum=st[2*pos+1].sum+st[2*pos+2].sum;
    st[pos].ls=max(st[2*pos+1].sum+st[2*pos+2].ls,st[2*pos+1].ls);
    st[pos].rs=max(st[2*pos+2].sum+st[2*pos+1].rs,st[2*pos+2].rs);
    st[pos].ms=max(st[pos].ls,max(st[pos].rs,max(st[pos].sum,max(st[2*pos+1].ms,max(st[2*pos+2].ms,st[2*pos+1].rs+st[2*pos+2].ls)))));
}
node* query(ll ql,ll qu,ll l,ll u,ll pos){
    if(l>=ql&&u<=qu){
        return &st[pos];
    }
    if(l>qu||ql>u){
        node* tt=(node*)malloc(sizeof(node));
        tt->ls=tt->ms=tt->rs=tt->sum=-1000000;
        return tt;
    }
    ll m=l+(u-l)/2;
    node* left=query(ql,qu,l,m,2*pos+1);
    node* right=query(ql,qu,m+1,u,2*pos+2);
    node* ans=(node*)malloc(sizeof(node));
    ans->sum=left->sum+right->sum;
    ans->ls=max(left->sum+right->ls,left->ls);
    ans->rs=max(right->sum+left->rs,right->rs);
    ans->ms=max(ans->ls,max(ans->rs,max(ans->sum,max(left->ms,max(right->ms,left->rs+right->ls)))));
    return ans;
}
void update(ll ql,ll qu,ll l,ll u,ll v,ll pos){
    if(l>=ql&&u<=qu){
        st[pos].ls=st[pos].rs=st[pos].ms=st[pos].sum=v;
        return;
    }
    if(l>qu||ql>u)
        return;
    ll m=l+(u-l)/2;
    update(ql,qu,l,m,v,2*pos+1);
    update(ql,qu,m+1,u,v,2*pos+2);
    st[pos].sum=st[2*pos+1].sum+st[2*pos+2].sum;
    st[pos].ls=max(st[2*pos+1].sum+st[2*pos+2].ls,st[2*pos+1].ls);
    st[pos].rs=max(st[2*pos+2].sum+st[2*pos+1].rs,st[2*pos+2].rs);
    st[pos].ms=max(st[pos].ls,max(st[pos].rs,max(st[pos].sum,max(st[2*pos+1].ms,max(st[2*pos+2].ms,st[2*pos+1].rs+st[2*pos+2].ls)))));
}
int main(){
	ll n;
	sfd(n);
	ll i,a[n];
	for(i=0;i<n;i++)
        sfd(a[i]);
    maketree(a,0,n-1,0);
    ll m;
    sfd(m);
    while(m--){
        ll c,x,y;
        sfd(c);
        sfd(x);sfd(y);
        if(c==0){
            x--;
            update(x,x,0,n-1,y,0);
        }
        else{
            x--;y--;
            node* ans=query(x,y,0,n-1,0);
            pf("%lld\n",ans->ms);
        }
    }
}
