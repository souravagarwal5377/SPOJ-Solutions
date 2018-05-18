ll p[1000001];
ll d[1000001]={0};
void makeset(ll n){
	ll i;
	for(i=0;i<=n;i++)
		p[i]=i;
}
ll findset(ll x){
	if(p[x]==x)
		return x;
	p[x]=findset(p[x]);
	return p[x];
}
void unionset(ll x,ll y){
	ll sx=findset(x);
	ll sy=findset(y);
	if(sx==sy)
		return;// in same set
	if(d[sx]<=d[sy]){
		p[sx]=sy;
		d[sy]=(d[sx]==d[sy])?d[sy]+1:d[sy];
	}
	else
		p[sy]=sx;
}