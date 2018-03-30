#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
ll func(ll *a,ll n){
    pair<ll,ll> m[105][105];
    ll s,e,l,x,i;
    for(i=0;i<n;i++)
            m[i][i]=make_pair(a[i],0);
    for(l=2;l<=n;l++){
        for(s=0;s<n-l+1;s++){
            e=s+l-1;
            m[s][e].second=INT_MAX;
            for(i=s;i<e;i++){
                x=m[s][i].second+m[i+1][e].second+(m[s][i].first*m[i+1][e].first);
                if(x<m[s][e].second){
                    m[s][e].second=x;
                    m[s][e].first=(m[s][i].first+m[i+1][e].first)%100;
                }
            }
        }
    }
    return m[0][n-1].second;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n;
    while(cin>>n){
    	ll i,a[n];
    	for(i=0;i<n;i++)
    		sfd(a[i]);
    	ll ans=func(a,n);
        cout<<ans<<endl;
    }
}
