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
	while(1){
		ll b,n;
		sfd(b);sfd(n);
		if(b==0&&n==0)
			break;
		ll e[n+1],f[n+1],i;
		for(i=1;i<=n;i++){
			sfd(e[i]);sfd(f[i]);
		}
		ll a[n+1][b+1]={0};
		for(i=1;i<=n;i++){
			for(ll j=1;j<=b;j++){
				if(e[i]>j)
					a[i][j]=a[i-1][j];
				else{
					a[i][j]=max(a[i-1][j],f[i]+a[i-1][j-e[i]]);
				}
			}
		}
		for(i=0;i<=b;i++){
			if(a[n][i]==a[n][b])
				break;
		}
		cout<<i<<" "<<a[n][b]<<endl;
	}

}