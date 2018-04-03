#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll reverse(ll n){    /*returns the reverse of number n*/
	ll i,r=0;
	while(n>0){
		i=n%10;
		r=r*10+i;
		n/=10;
	}
	return r;
}
ll countinfactn(ll n,ll i){   /*returns the number of times a prime number*/
	ll c=0,k=i;					/* i appears in n!*/
	while(i<=n){
		c=c+(n/i);
		i=i*k;
	}
	return c;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll m,n,cnt=0;
		char a[1002][1002];
		cin>>n>>m;
		ll i,j;
		for(i=0;i<m;i++)
			cin>>a[i];
		ll vis[1001][1001]={0};
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(a[i][j]=='.'&&vis[i][j]==0){
					vis[i][j]=1;
					queue<pair<ll,ll> > q,q1;
					q.push(make_pair(i,j));
					ll mx[]={-1,1,0,0};
					ll my[]={0,0,1,-1};
					ll c=0;
					while(!q.empty()){
						c++;
						while(!q.empty()){
							pair<ll,ll> p=q.front();
							ll x=p.first;
							ll y=p.second;
							q.pop();
							for(ll k=0;k<4;k++){
								if(x+mx[k]>=0&&y+my[k]>=0&&x+mx[k]<m&&y+my[k]<n&&vis[x+mx[k]][y+my[k]]==0&&a[x+mx[k]][y+my[k]]=='.'){
									vis[x+mx[k]][y+my[k]]=1;
									q1.push(make_pair(x+mx[k],y+my[k]));
								}
							}
						}
						q.swap(q1);
					}
					if(c>cnt)
						cnt=c;
				}
			}
		}
		if(cnt==0)
			cnt=1;
		cout<<"Maximum rope length is "<<cnt-1<<"."<<endl;
	}
}