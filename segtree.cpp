ll st[1000001];
ll lazy[1000001];
void maketree(ll *a,ll l,ll u,ll pos){
	if(l==u){
		st[pos]=a[l];
		return;
	}
	ll mid=l+(u-l)/2;
	maketree(a,l,mid,2*pos+1);
	maketree(a,mid1,u,2*pos+2);
	st[pos]=min(st[2*pos+1],st[2*pos+2]);
}
ll query(ll ql,ll qu,ll l,ll u,ll pos){
	if(lazy[pos]!=0){
		st[pos]=;
		if(l!=u){
			lazy[2*pos+1]=lazy[pos];
			lazy[2*pos+2]=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(l>=ql&&u<=qu)
		return st[pos];
	if(l>qu||ql>u)
		return INT_MAX;
	ll mid=l+(u-l)/2;
	ll left=query(ql,qu,l,mid,2*pos+1);
	ll right=query(ql,qu,mid+1,u,2*pos+2);
	return min(left,right);
}
void update(ll ql,ll qu,ll l,ll u,ll pos,ll val){
	if(lazy[pos]!=0){
		st[pos]=;
		if(l!=u){
			lazy[2*pos+1]=lazy[pos];
			lazy[2*pos+2]=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(l>=ql&&u<=qu){
		st[pos]+=val;
		lazy[2*pos+1]+=val;
		lazy[2*pos+2]+=val;
	}
	if(l>qu||ql>u)
		return;
	ll mid=l+(u-l)/2;
	update(ql,qu,l,mid,2*pos+1,val);
	update(ql,qu,mid+1,u,2*pos+2,val);
}