#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
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
	ll n,k;
	sfd(n);sfd(k);
	ll i,x[n+1],a[n];
	x[0]=0;
	map<ll,ll> m;
	m[0]++;
	for(i=0;i<n;i++){
		sfd(a[i]);
		x[i+1]=x[i]+a[i];
		m[x[i+1]]++;
	}
	ll ans=0;
	if(k==1){
		for(i=0;i<=n;i++){
			ans+=m[1+x[i]];
		}
		cout<<ans/2<<endl;
		return 0;
	}
	else if(k==-1){
		for(i=0;i<=n;i++){
			ans+=m[1+x[i]];
			ans+=m[-1+x[i]];
		}
		cout<<ans/2<<endl;
		return 0;
	}
	else{
		ll p=1;
		for(i=0;i<=n;i++){
			p=1;
			while(abs(p)<=100000000000000){
				ans+=m[x[i]+p];
				p=p*k;
			}
		}
		cout<<ans/2<<endl;
		return 0;
	}
}