#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int main()
{
    while(1)
    {
        ll n,i;
        sfd(n);
        if(n==0)
            break;
        ll a[n],j=1;
        stack<ll> s;
        for(i=0;i<n;i++)
        {
            ll x;
            sfd(x);
            while(!s.empty()&&s.top()==j){
                s.pop();
                //cout<<"Passing "<<j<<endl;
                j++;
            }
            if(x==j)
            {
                //cout<<"Passing "<<j<<endl;
                j++;
            }
            else
                s.push(x);
        }
        while(!s.empty()&&s.top()==j)
        {
            s.pop();
            j++;
        }
        if(j==n+1)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
