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
	ll f[3]={0},i;
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		if(s[2]=='2')
			f[1]++;
		else if(s[0]=='1')
			f[0]++;
		else
			f[2]++;
	}
	ll s=1;
	s=s+f[2];
	if(f[0]<=f[2])
		f[0]=0;
	else
		f[0]=f[0]-f[2];
	s=s+(f[1]/2);
	if(f[1]%2==1)
		f[1]=1;
	else
		f[1]=0;
	if(f[1]==1){
		if(f[0]>=2){
			s=s+1;
			f[0]-=2;
		}
		else{
			s++;
			f[0]=0;
		}
	}
	s=s+(f[0]/4);
	if(f[0]%4!=0)
		s++;
	cout<<s<<endl;
}