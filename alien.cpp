#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
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
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		sfd(n);sfd(m);
		ll i,a[n+1],x;
		a[0]=0;
		//cout<<a[0]<<" ";
		for(i=1;i<=n;i++){
			sfd(x);
			a[i]=a[i-1]+x;
			//cout<<a[i]<<" ";
		}
		//cout<<endl;
		ll ans=0,ap=-1;
		for(i=1;i<=n;i++){
			x=m+a[i-1];
			//cout<<x<<" ";
			ll p=upper_bound(a,a+n+1,x)-a;
			//cout<<p<<endl;
			if(a[p]>x)
				p--;
			ll c=p-i+1;
			if(c>ans){
				ans=c;
				ap=a[p]-a[i-1];
			}
			else if(c==ans&&a[p]-a[i-1]<ap){
				ans=c;
				ap=a[p]-a[i-1];	
			}
		}
		cout<<ap<<" "<<ans<<endl;
	}
}