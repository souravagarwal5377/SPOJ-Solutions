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
ll mx[4]={-1,1,0,0};
ll my[4]={0,0,-1,1};
//ll mx[8]={-1,1,0,0,-1,-1,1,1};
//ll my[8]={0,0,-1,1,-1,1,-1,1};
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	sfd(n);
	ll d[10],dr[10];
	for(ll i=0;i<10;i++)
	    d[i]=dr[i]=-1;
	//cout<<n<<endl;
	ll c=0;
	ll x=n;
	vector<ll> pos;
	while(x>0){
		ll di=x%10;
		if(di==0)
			pos.pb(c);
		if(d[di]==-1)
			d[di]=c;
		dr[di]=c;
		x/=10;
		c++;
	}
	ll ppp=0;
	for(i=1;i<=9;i++){
		ppp=max(ppp,dr[i]);
	}
	ppp=ppp-c;
	ll m=INT_MAX;
	if(d[2]>=0&&d[5]>=0){
		ll x=d[5]+d[2]-1;
		if(d[2]<d[5])	
			x++;
		if(d[5]==)
		m=min(m,x);
	}
	if(d[7]>=0&&d[5]>=0){
		ll x=d[5]+d[7]-1;
		if(d[7]<d[5])
			x++;
		m=min(m,x+temp);
	}
	if(d[0]>=0&&d[5]>=0){
		ll x=d[0]+d[5]-1;
		if(d[5]<d[0])
			x++;
		m=min(m,x);
	}
	if(pos.size()>=2){
		ll x=pos[0]+pos[1]-1;
		m=min(x,m);
	}
	if(m==INT_MAX)
		cout<<"-1\n";
	else
		cout<<m<<endl;
}