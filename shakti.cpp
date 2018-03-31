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
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2==0)
			cout<<"Thankyou Shaktiman"<<endl;
		else
			cout<<"Sorry Shaktiman"<<endl;
	}
}