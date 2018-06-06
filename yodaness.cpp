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
ll ans;
void merge(ll a[],ll l,ll m,ll u){
	ll x=m-l+1,y=u-m;
	ll left[x],right[y];
	ll i,j=0;
	for(i=l;i<=m;i++){
		left[j++]=a[i];
	}
	j=0;
	for(i=m+1;i<=u;i++){
		right[j++]=a[i];
	}
	ll k=0;
	i=l,j=0;
	while(j<x&&k<y){
		if(left[j]<=right[k])
			a[i++]=left[j++];
		else{
			ans=ans+(x-1-j+1);
			a[i++]=right[k++];
		}
	}
	while(j<x)
		a[i++]=left[j++];
	while(k<y)
		a[i++]=right[k++];
}
void cnt(ll a[],ll l,ll u){
	if(l>=u)
		return;
	ll m=l+(u-l)/2;
	cnt(a,l,m);
	cnt(a,m+1,u);
	merge(a,l,m,u);
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n;
		map<string,ll> id;
		vector<string> v;
		sfd(n);
		ll i;
		for(i=0;i<n;i++){
			string s;
			cin>>s;
			v.pb(s);
		}
		for(i=0;i<n;i++){
			string s;
			cin>>s;
			id[s]=i;
		}
		ll a[n];
		for(i=0;i<n;i++){
			a[i]=id[v[i]];
		}
		ans=0;
		cnt(a,0,n-1);
		cout<<ans<<endl;
	}
}