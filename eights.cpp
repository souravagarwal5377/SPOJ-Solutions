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
ll countinfactn(ll n,ll i){   
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
	while(t--){
		ll n;
		cin>>n;
		n--;
		ll d=n%4;
		ll x=n/4;
		if(d==0&&x!=0){
			cout<<x<<"192"<<endl;
		}
		else if(d==1&&x!=0){
			cout<<x<<"442"<<endl;
		}
		else if(d==2&&x!=0)
			cout<<x<<"692"<<endl;
		else if(d==3&&x!=0)
			cout<<x<<"942"<<endl;
		else if(d==0)
			cout<<"192"<<endl;
		else if(d==1)
			cout<<"442"<<endl;
		else if(d==2)
			cout<<"692"<<endl;
		else
			cout<<"942"<<endl;
	}
}