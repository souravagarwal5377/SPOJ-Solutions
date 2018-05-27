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
	ll t;
	cin>>t;
	while(t--){
		string s[183];
		ll m,n,i,j;
		sfd(m);sfd(n);
		for(i=0;i<m;i++)
			cin>>s[i];
		ll vis[183][183]={0};
		ll ans[183][183];
		queue<pair<ll,ll> > q;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(s[i][j]=='1'){
					q.push(make_pair(i,j));
					vis[i][j]=1;
					ans[i][j]=0;
				}
			}
		}
		while(!q.empty()){
			pair<ll,ll> p=q.front();
			ll x=p.first,y=p.second;
			q.pop();
			ll mx[]={-1,1,0,0};
			ll my[]={0,0,-1,1};
			for(i=0;i<4;i++){
				if(x+mx[i]>=0&&x+mx[i]<m&&y+my[i]>=0&&y+my[i]<n&&vis[x+mx[i]][y+my[i]]==0){
					q.push(make_pair(x+mx[i],y+my[i]));
					ans[x+mx[i]][y+my[i]]=ans[x][y]+1;
					vis[x+mx[i]][y+my[i]]=1;
				}
			}
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
}