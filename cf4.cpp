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
	pair<int,char> p[4];
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    p[0]=make_pair(a,'A');
    p[1]=make_pair(b,'B');
    p[2]=make_pair(c,'C');
    p[3]=make_pair(d,'D');
    sort(p,p+4);
    char mat[51][51];
    
}