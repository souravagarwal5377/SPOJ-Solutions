#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
using namespace std;
ll bfs(string s[],ll n,ll m){
	ll vis[1000][1000]={0};
	ll cnt=0,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(vis[i][j]==0){
				queue<pair<ll,ll> > q;
				q.push(make_pair(i,j));
				vis[i][j]=1;
				while(!q.empty()){
					pair<ll,ll> p=q.front();
					ll u=p.first,v=p.second;
					q.pop();
					if(s[u][v]=='N'&&vis[u-1][v]==0){
						vis[u-1][v]=1;
						q.push(make_pair(u-1,v));
					}
					else if(s[u][v]=='S'&&vis[u+1][v]==0){
						vis[u+1][v]=1;
						q.push(make_pair(u+1,v));
					}
					else if(s[u][v]=='E'&&vis[u][v+1]==0){
						vis[u][v+1]=1;
						q.push(make_pair(u,v+1));
					}
					else if(s[u][v]=='W'&&vis[u][v-1]==0){
						vis[u][v-1]=1;
						q.push(make_pair(u,v-1));
					}
					if(u+1<n&&s[u+1][v]=='N'&&vis[u+1][v]==0){
						vis[u+1][v]=1;
						q.push(make_pair(u+1,v));
					}
					if(u-1>=0&&s[u-1][v]=='S'&&vis[u-1][v]==0){
						vis[u-1][v]=1;
						q.push(make_pair(u-1,v));
					}
					if(v-1>=0&&s[u][v-1]=='E'&&vis[u][v-1]==0){
						vis[u][v-1]=1;
						q.push(make_pair(u,v-1));
					}
					if(v+1<m&&s[u][v+1]=='W'&&vis[u][v+1]==0){
						vis[u][v+1]=1;
						q.push(make_pair(u,v+1));
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n,m,i;
	sfd(n);sfd(m);
	string s[n];
	for(i=0;i<n;i++)
		cin>>s[i];
	ll ans=bfs(s,n,m);
	cout<<ans<<endl;
}