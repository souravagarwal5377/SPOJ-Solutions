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
/*
inline void sfd(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}*/
ll toint(string s){
	ll n=0,i;
	for(i=0;i<s.length();i++){
		n=n*10+((ll)(s[i])-48);
	}
	//cout<<n<<endl;
	return n;
}
ll dectobin(ll n){
	stack<ll> s;
	while(n>=2){
		ll x=n%2;
		s.push(x);
		n=n/2;
	}
	s.push(n);
	ll ans=0;
	while(!s.empty()){
		ans=ans*10+s.top();
		s.pop();
	}
	return ans;
}
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
string tostring(ll n){
	ll x,p=0;
	string s;
	while(n>0){
		ll d=n%10;
		s=s+(char)(d+48);
		n/=10;
	}
	reverse(s.begin(),s.end());
	//cout<<s<<endl;
	return s;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n,e,t,i,m;
	cin>>n>>e>>t>>m;
	vector<pair<ll,ll> > v[n+1];
	for(i=0;i<m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		v[x].pb(make_pair(z,y));
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		if(i==e){
			ans++;
			continue;
		}
		priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
		ll vis[n+1]={0};
		ll d[n+1],j;
		for(j=1;j<=n;j++)
			d[j]=INT_MAX;
		d[i]=0;
		pq.push(make_pair(0,i));
		while(!pq.empty()){
			ll x=pq.top().second;
			pq.pop();
			vis[x]=1;
			for(j=0;j<v[x].size();j++){
				if(vis[v[x][j].second]==0&&d[v[x][j].second]>d[x]+v[x][j].first){
					d[v[x][j].second]=d[x]+v[x][j].first;
					pq.push(make_pair(d[v[x][j].second],v[x][j].second));
				}
			}
		}
		if(d[e]<=t)
			ans++;
	}
	cout<<ans<<endl;
}