#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll a[1000001]={0};
vector<ll> v;
void cubefree(){
	ll i,j;
	for(i=2;i*i*i<=1000000;i++){
		ll x=i*i*i;
		if(a[x]==0){
			a[x]=1;
			for(j=2*x;j<=1000000;j+=x)
				a[j]=1;
		}
	}
	for(i=1;i<=1000000;i++){
		if(a[i]==0)
			v.push_back(i);
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cubefree();
    ll int t;   
    scanf("%lld",&t);
    ll u=0;
    while(t--)
    {
    	u++;
        ll x;
        sfd(x);
        if(a[x]==1)
        	cout<<"Case "<<u<<": "<<"Not Cube Free\n";
        else{
        	ll pp=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
        	cout<<"Case "<<u<<": "<<pp<<endl;
        }
    } 
}
