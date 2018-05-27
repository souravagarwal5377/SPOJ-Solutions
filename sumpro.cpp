#include <bits/stdc++.h>
 
#define pii pair <int,int>
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define oo 1<<29
#define dd double
#define ll long long
#define EPS 10E-10
#define ff first
#define ss second
#define MAX 10000
#define CIN ios_base::sync_with_stdio(0)
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define getint2(a,b) scanf("%d%d",&a,&b)
#define getint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define loop(i,n) for(int i=0;i<n;i++)
#define TEST_CASE(t) for(int z=1;z<=t;z++)
#define PRINT_CASE printf("Case %d: ",z)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 1000000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define mod 1000000007
#define I int
 
using namespace std;
 
/* Bits operation */
int Set(int n,int pos)  { return n = n | 1<<pos;}
bool check(int n,int pos) { return n & 1<<pos;}
int Reset(int n, int pos) { return n=n & ~(1<<pos);}
 /*----------------*/
 
 ll range_sum(ll a, ll b)
 {
     ll sa=a*(a+1)>>1;
     ll sb=b*(b+1)>>1;
     return (sa-sb)%mod;
 }
 
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    ll n;
    getint(t);
    TEST_CASE(t)
    {
        sc("%lld",&n);
        ll root=sqrt(n);
        ll low,up;
        ll sum=0;
        for(int i=1;i<=root;i++)
        {
            up=n/i;
            low=max(n/(i+1),root);
            sum+=(range_sum(up,low)*i)%mod;
            if(sum>=mod) sum-=mod;
            sum+=(i*(n/i))%mod;
            if(sum>=mod) sum-=mod;
        }
        pf("%lld\n",sum);
    }
    return 0;
}