#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	sfd(n);
	ll i,c[3]={0},ans=1;
	for(i=0;i<n;i++){
	    string s;
		cin>>s;
		if(s[0]=='1'){
			if(s[2]=='2')
				c[1]++;
			else
				c[0]++;
		}
		else
			c[2]++;
	}
	ans+=c[2];
	ll f=0;
	if(c[0]<=c[2])
		c[0]=0;
	else
		c[0]-=c[2];
	if(c[1]%2==0){
		ans+=(c[1]/2);
	}
	else{
		ans+=(c[1]/2)+1;
		f=1;
	}
	if(c[0]<=2){
		if(f==0)
			ans++;
		cout<<ans<<endl;
		return 0;
	}
	else{
		if(f==1)
			c[0]-=2;
		ans+=(c[0]/4);
		if(c[0]%4!=0)
			ans++;
		cout<<ans<<endl;
		return 0;
	}
}