#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll reverse(ll n){    /*returns the reverse of number n*/
	ll i,r=0;
	while(n>0){
		i=n%10;
		r=r*10+i;
		n/=10;
	}
	return r;
}
ll countinfactn(ll n,ll i){   /*returns the number of times a prime number i appears in n!*/
	ll c=0,k=i;
	while(i<=n){
		c=c+(n/i);
		i=i*k;
	}
	return c;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	cin>>t;
	map<pair<ll,ll> , ll> m;
	m[make_pair(0,0)]=0;
	ll x=0,y=0;
	for(ll i=1;i<=10000;i++){
		if(i%4==1){
			x++;y++;
		}
		else if(i%4==2){
			x++; y--;
		}
		else if(i%4==3){
			x++;y++;
		}
		else{
			x--;y++;
		}
		m[make_pair(x,y)]=i;
	}
	while(t--){
		cin>>x>>y;
		if(m[make_pair(x,y)]!=0||(x==0&&y==0))
			cout<<m[make_pair(x,y)]<<endl;
		else
			cout<<"No Number\n";
	}
}