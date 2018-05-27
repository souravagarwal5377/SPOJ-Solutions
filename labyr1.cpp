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
ll mx[4]={-1,1,0,0};
ll my[4]={0,0,-1,1};
char a[1005][1005];
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t,m,n,i,j;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<m;i++)
			cin>>a[i];
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(a[i][j]=='.')
					break;
			}
			if(j!=n)
				break;
		}
		if(i==m&&j==n){
			cout<<"0\n";
			continue;
		}
		queue<pp> q;
		ll vis[1001][1001]={0};
		q.push(make_pair(i,j));
		vis[i][j]=1;
		ll cnt=0;
		while(!q.empty()){
			ll ss=q.size();
			//cout<<ss<<endl;
			while(ss--){
				ll x=q.front().first;
				ll y=q.front().second;
				q.pop();
				for(i=0;i<4;i++){
					if(x+mx[i]>=0&&x+mx[i]<m&&y+my[i]>=0&&y+my[i]<n&&vis[x+mx[i]][y+my[i]]==0&&a[x+mx[i]][y+my[i]]=='.'){
						q.push(make_pair(x+mx[i],y+my[i]));
						vis[x+mx[i]][y+my[i]]=1;
					}
				}
			}
			cnt++;
		}
		cout<<"Maximum rope length is "<<cnt-1<<"."<<endl;
	}
}