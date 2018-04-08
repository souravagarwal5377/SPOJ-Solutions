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
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		sfd(n);sfd(k);
		ll i,a[n],sum=0;
		for(i=0;i<n;i++){
			sfd(a[i]);
			sum+=a[i];
		}
		ll v=sum/k,s=a[0],f=0,cnt=0;
		cout<<a[0]<<" ";
		for(i=1;i<n;i++){
			if(s+a[i]<v){
				s+=a[i];
				cout<<a[i]<<" ";
			}
			else if(s+a[i]==v){
				s=0;
				cout<<a[i]<<" ";
				if(cnt<k-1){
					cout<<"/ ";
					cnt++;
				}
			}
			else{
				if(s==0){
					s=0;
					cout<<a[i]<<" ";
					if(cnt<k-1){
					cout<<"/ ";
					cnt++;
					}
				}
				else{
					s=a[i];
					if(cnt<k-1){
					cout<<"/ ";
					cnt++;
					}
					cout<<a[i]<<" ";
				}
			}
		}
		cout<<endl;
	}
}