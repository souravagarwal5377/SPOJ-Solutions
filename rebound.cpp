#include<stdio.h>
#include<math.h>
#define ll long long

int main()
{
    ll t;
    double x,y,z;
    ll ans;
    double d;
    scanf("%lld",&t);
    while(t--)
    {
        d=0.0;
        scanf("%lf%lf%lf",&x,&y,&z);
        d=(x*z+z*sqrt(x*x+y*(y+2.0*z)))/(y+2.0*z);
        //printf("%lf\n",d);
        if(d-(ll)(d)!=0.0)
        {
            printf("Not this time.\n");
        }
        else
        {
            ans=d;
            printf("%lld\n",ans);
        }
    }
    return 0;
}