#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
char a[51][51];
ll bfs(ll x,ll y,ll m,ll n){
	queue<pair<ll,ll> >q,q1;
	q.push(make_pair(x,y));
	ll vis[50][50]={0};
	ll mx[]={-1,1,0,0,1,-1,-1,1};
	ll my[]={0,0,1,-1,1,-1,1,-1};
	vis[x][y]=1;
	ll c=1,f=0;
	while(1){
	    while(!q.empty()){
		    x=q.front().first;
		    y=q.front().second;
		    q.pop();
		    for(ll i=0;i<8;i++){
			    if(x+mx[i]>=0 && x+mx[i]<=m && y+my[i]>=0 && y+my[i]<=n && (a[x+mx[i]][y+my[i]]-a[x][y]==1) && vis[x+mx[i]][y+my[i]]==0){
				    q1.push(make_pair(x+mx[i],y+my[i]));
				    vis[x+mx[i]][y+my[i]]=1;
			    }
		    }
	    }
	    if(!q1.empty())
		    c++;
		q.swap(q1);
		if(q.empty()==true)
		    break;
	}
	return c;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    ll p=1;
	while(1){
		ll m,n;
		sfd(m);sfd(n);
		if(m==0&&n==0)
			break;
		ll i,j;
		queue<pair<ll,ll> >q;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]=='A')
					q.push(make_pair(i,j));
			}
		}
		ll x,y,ans=0;
		while(!q.empty()){
			x=q.front().first;
			y=q.front().second;
			q.pop();
			ll aa=bfs(x,y,m-1,n-1);
			if(aa>ans)
				ans=aa;
		}
		cout<<"Case "<<p<<": "<<ans<<endl;
		p++;
	}
}