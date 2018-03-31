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
	ll n,x;
	sfd(n);
	x=n%10;
	if(x==0){
		cout<<"2"<<endl;
	}
	else
		cout<<"1"<<endl<<x<<endl;
}