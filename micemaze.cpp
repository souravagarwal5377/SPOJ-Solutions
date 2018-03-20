#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll a[101][101]={0};
bool bfs(ll s,ll e,ll *t,ll l){
    if((*time)>t)
        return false;

}
int main(){
	ll n,e,t,c,i,x,y,z;
	sfd(n);sfd(e);sfd(t);sfd(c);
	for(i=0;i<c;i++){
        sfd(x);sfd(y);sfd(z);
        a[x][y]=z;
	}
	for(i=1;i<=n;i++){
        ll time=0;
        bfs(i,e,&time,t);
	}
}
