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
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll s=a[0],lv=a[0];
	ll lb=k/2;
	ll ub=n*k-1-k/2;
	if(k%2!=0){
		if(a[lb]-a[lb-1]>a[ub+1]-a[ub])
			lb++;
		else
			ub--;
	}
	ll cd=0;
	//cout<<s<<endl;
	for(i=1;i<n&&lb<ub;i++){
		ll cv=a[lb];
		s+=cv;
		cd=cd+(cv-lv);
		lv=cv;
		lb=lb+k/2;
		ub=ub-k/2;	
		if(k%2!=0){
			if(a[lb]-a[lb-1]>a[ub+1]-a[ub])
				lb++;
			else
				ub--;
		}	
	}
	if(cd>l)
		cout<<"0\n";
	else
		cout<<s<<endl;
}