#include<bits/stdc++.h>
#define ll int
//#define sfd(x) scanf("%d",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
#define M 1000000007
#define pp pair<ll,ll>
#define pb push_back
#define inf INT_MAX;
using namespace std;
inline void sfd(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}
struct stu{
	ll l;
	ll r;
	ll p;
}q[200000];
ll n;
ll a[30000];
bool my(stu a,stu b){
	if((a.l/174)!=(b.l/174))
		return (a.l/174)<(b.l/174);
	else
		return (a.r)<(b.r);
}
ll f[1000001]={0};
ll cnt=0;
void add(ll pos){
	f[a[pos]]++;
	if(f[a[pos]]==1)
		cnt++;
}
void remove(ll pos){
	f[a[pos]]--;
	if(f[a[pos]]==0)
		cnt--;
}
ll ans[200000];
int main(){
	sfd(n);
	ll i;
	for(i=0;i<n;i++)
		sfd(a[i]);
	ll query;
	sfd(query);
	for(i=0;i<query;i++){
		sfd(q[i].l);sfd(q[i].r);
		q[i].l--;q[i].r--;
		q[i].p=i;
	}
	sort(q,q+query,my);
	ll x,y;
	x=y=0;
	for(i=0;i<query;i++){
		while(x<q[i].l){
			remove(x);
			x++;
		}
		while(x>q[i].l){
			add(x-1);
			x--;
		}
		while(y<=q[i].r){
			add(y);
			y++;
		}
		while(y>(q[i].r+1)){
			remove(y-1);
			y--;
		}
		ans[q[i].p]=cnt;
	}
	for(i=0;i<query;i++)
		pf("%d\n",ans[i]);
}