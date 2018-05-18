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
ll prime(ll n){
	ll i=2,k=0;
	while(i*i<=n){
		if(n%i==0)
			k++;
		i++;
	}
	if(k==0)
		return 1;
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    ll i;
    map<ll,ll> m;
    for(i=1001;i<=9999;i+=2){
    	if(prime(i)==1)
    		m[i]=1;
    }
  	vector<ll> v[10001];
  	ll a,b,c,d,j;
  	for(i=1001;i<=9999;i+=2){
  		if(m[i]==1){
  			a=i/1000;
  			b=(i/100)%10;
  			c=(i/10)%10;
  			d=i%10;
  			for(j=1;j<=9;j++){
  				ll x=(j*10)+b;
  				x=x*10+c;
  				x=x*10+d;
  				if(j!=a&&m[x]==1)
  					v[i].pb(x);
  			}
  			for(j=0;j<=9;j++){
  				ll x=(a*10)+j;
  				x=x*10+c;
  				x=x*10+d;
  				if(j!=b&&m[x]==1)
  					v[i].pb(x);
  			}
  			for(j=0;j<=9;j++){
  				ll x=(a*10)+b;
  				x=x*10+j;
  				x=x*10+d;
  				if(j!=c&&m[x]==1)
  					v[i].pb(x);
  			}
  			for(j=0;j<=9;j++){
  				ll x=(a*10)+b;
  				x=x*10+c;
  				x=x*10+j;
  				if(j!=d&&m[x]==1)
  					v[i].pb(x);
  			}
  		}
  	}
	ll t;
	cin>>t;
	// for(i=0;i<v[1733].size();i++)
	// 	cout<<v[1733][i]<<" ";
	// cout<<endl;
	while(t--){
		cin>>a>>b;
		ll vis[10001]={0};
		queue<ll> q,q1;
		ll cost=0,f=0;
		q.push(a);
		vis[a]=1;
		while(1){
			while(!q.empty()){
				c=q.front();
				q.pop();
				if(c==b){
					f=1;
					break;
				}
				for(i=0;i<v[c].size();i++){
					if(vis[v[c][i]]==0){
						vis[v[c][i]]=1;
						q1.push(v[c][i]);
					}
				}
			}
			q.swap(q1);
			if(f==1||(q.empty()&&q1.empty()))
				break;
			cost++;
		}
		if(f==0)
			cout<<"Impossible\n";
		else
			cout<<cost<<endl;
	}
}