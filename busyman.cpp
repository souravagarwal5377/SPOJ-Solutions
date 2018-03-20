#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
        ll n;
        sfd(n);
        ll i;
        vector<pair<ll,ll> > v;
        for(i=0;i<n;i++){
            ll x,y;
            sfd(x);sfd(y);
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        ll cnt=1,e=v[0].second;
        for(i=1;i<n;i++){
            if(v[i].first>=e){
                cnt++;
                e=v[i].second;
            }
            if(v[i].second<e){
                e=v[i].second;
            }
        }
        cout<<cnt<<endl;
	}
}
