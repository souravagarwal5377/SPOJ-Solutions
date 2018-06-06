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
	ll f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	vector<ll> v[f+1];
	for(i=1;i<=f;i++){
		if(i+u<=f)
			v[i].pb(i+u);
		if(i-d>=1)
			v[i].pb(i-d);
	}
	queue<ll> q;
	q.push(s);
	ll vis[f+1]={0};
	vis[s]=1;
	ll par[f+1]={0};
	while(!q.empty()){
		ll t=q.front();
		q.pop();
		for(i=0;i<v[t].size();i++){
			if(vis[v[t][i]]==0){
				vis[v[t][i]]=1;
				par[v[t][i]]=t;
				q.push(v[t][i]);
			}
		}
	}
	if(vis[g]==0){
		cout<<"use the stairs"<<endl;
	}
	else{
		stack<ll> st;
		ll p=par[g];
		st.push(g);
		while(p!=0){
			st.push(p);
			p=par[p];
		}
		cout<<st.size()<<endl;
	}
}