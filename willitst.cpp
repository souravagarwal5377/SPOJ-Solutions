#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	unsigned ll n,f=0;
	cin>>n;
	map<unsigned ll,unsigned ll> m;
	while(n>1){
		if(m[n]==1){
			f=1;
			break;
		}
		m[n]=1;
		if(n%2==0)
			n=n/2;
		else
			n=3*n+3;
	}
	if(f==0)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE\n";
}