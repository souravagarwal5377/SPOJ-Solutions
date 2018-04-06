#include<bits/stdc++.h>
#define ll long long
//#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
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
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	int n;
	sfd(n);
	int i,x[n];
	for(i=0;i<n;i++)
		sfd(x[i]);
	sort(x,x+n);
	int a,b,c,d,e,f,s=0,j,k,l,temp;
	vector<int> v;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(x[k]==0)
					continue;
				v.push_back((x[i]+x[j])*x[k]);
			}
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<n;i++){
		a=x[i];
		for(j=0;j<n;j++){
			b=x[j];
			for(k=0;k<n;k++){
				c=x[k];
				temp=a*b+c;
				bool se=binary_search(v.begin(),v.end(),temp);
				if(se==true){
					s=s+(upper_bound(v.begin(), v.end(),temp)-lower_bound(v.begin(), v.end(),temp));
				}
			}
		}
	}
	pf("%d\n",s);
}