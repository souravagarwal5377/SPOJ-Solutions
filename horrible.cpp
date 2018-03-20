#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
void update(ll* st,ll *lazy,ll ql,ll qu,ll l,ll u,ll v,ll pos){
    if(lazy[pos]!=0){
        st[pos]+=lazy[pos];
        if(l!=u){
            ll mem=l+(u-l)/2;
            ll vv=lazy[pos]/(u-l+1);
            lazy[2*pos+1]+=(vv*(mem-l+1));
            lazy[2*pos+2]+=(vv*(u-(mem+1)+1));
        }
        lazy[pos]=0;
    }
    if(l>=ql&&u<=qu){
        st[pos]+=(v*(u-l+1));
        if(l!=u){
            ll mem=l+(u-l)/2;
            lazy[2*pos+1]+=(v*(mem-l+1));
            lazy[2*pos+2]+=(v*(u-(mem+1)+1));
        }
        return;
    }
    if(l>qu||u<ql)
        return;
    ll m=l+(u-l)/2;
    update(st,lazy,ql,qu,l,m,v,2*pos+1);
    update(st,lazy,ql,qu,m+1,u,v,2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}
ll query(ll *st,ll *lazy,ll ql,ll qu,ll l,ll u,ll pos){
    if(lazy[pos]!=0){
        st[pos]+=lazy[pos];
        if(l!=u){
            ll mem=l+(u-l)/2;
            ll vv=lazy[pos]/(u-l+1);
            lazy[2*pos+1]+=(vv*(mem-l+1));
            lazy[2*pos+2]+=(vv*(u-(mem+1)+1));
        }
        lazy[pos]=0;
    }
    if(l>=ql&&u<=qu){
        return st[pos];
    }
    if(l>qu||u<ql)
        return 0;
    ll m=l+(u-l)/2;
    ll left=query(st,lazy,ql,qu,l,m,2*pos+1);
    ll right=query(st,lazy,ql,qu,m+1,u,2*pos+2);
    return left+right;
}
int main()
{
    ll int t;
    scanf("%lld",&t);
    while(t--)
    {
        ll st[400001]={0};
        ll lazy[400001]={0};
        ll n,i,q;
        sfd(n);
        sfd(q);
        while(q--){
            ll c;
            sfd(c);
            if(c==0){
                ll x,y,v;
                sfd(x);sfd(y);sfd(v);
                x--;y--;
                update(&st[0],&lazy[0],x,y,0,n-1,v,0);
            }
            else{
                ll x,y;
                sfd(x);sfd(y);
                x--;y--;
                ll ans=query(&st[0],&lazy[0],x,y,0,n-1,0);
                pf("%lld\n",ans);
            }
        }
    }
}

