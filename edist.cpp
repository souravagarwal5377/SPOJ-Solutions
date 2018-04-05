#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
/* Utility function to get max of 2 integers */
ll a[2004][2004];
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	int t;
	cin>>t;
	while(t--){
		char x[2005],y[2005];
		cin>>x>>y;
    ll i,cst,j;
    ll lx=strlen(x),ly=strlen(y);
    for(i=0;i<=ly;i++)
      a[0][i]=i;
    for(i=0;i<=lx;i++)
      a[i][0]=i;
    for(i=1;i<=lx;i++){
      for(j=1;j<=ly;j++){
        cst=1;
        if(x[i-1]==y[j-1]){
          cst=0;
          a[i][j]=a[i-1][j-1];
        }
        else
          a[i][j]=min(a[i-1][j]+1,min(a[i][j-1]+1,a[i-1][j-1]+cst));
      }
    }
    cout<<a[lx][ly]<<endl;
	}
}