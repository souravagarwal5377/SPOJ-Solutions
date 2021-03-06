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
ll mx[4]={-1,1,0,0};
ll my[4]={0,0,-1,1};
//ll mx[8]={-1,1,0,0,-1,-1,1,1};
//ll my[8]={0,0,-1,1,-1,1,-1,1};
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll x,k,n,j;
		cin>>x>>k;
		n=2*x;
		ll i,a[k];
		for(i=0;i<k;i++){
			sfd(a[i]);
			a[i]--;
		}
		if(x==1){
			if(k>1||(k==1&&a[0]==1))
				cout<<"0\n";
			else
				cout<<"1\n";
			continue;
		}
		ll dp[122][122]={0};
		k=0;
		for(i=0;i<=x;i++)
			dp[0][i]=0;
		dp[0][1]=1;
		if(a[0]==0)
			k++;
		for(i=1;i<n;i++){
			for(j=1;j<x;j++){
				if(i==a[k]){
					dp[i][j]=dp[i-1][j-1];
				}
				else
					dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			}
			if(i==a[k]){
				dp[i][0]=0;
				dp[i][x]=dp[i-1][x-1];
				k++;
			}
			else{
				dp[i][0]=dp[i-1][1];
				dp[i][x]=dp[i-1][x-1];
			}
		}
		cout<<dp[n-1][0]<<endl;
	}
}