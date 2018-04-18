#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
/*
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
}*/
ll pa[10000000];
void precomputearray(string a){
	ll l=a.length();
	ll i,j=0;
	for(i=1;i<l;){
		if(a[i]==a[j]){
			pa[i]=1+j;
			i++;j++;
		}
		else{
			if(j==0){
				pa[i]=0;
				i++;
			}
			else{
				j=pa[j-1];
			}
		}
	}
}
void kmp(string a,string b){
	precomputearray(b);
	ll i,j=0;
	for(i=0;i<a.length();){
		if(a[i]==b[j]){
			i++;
			j++;
			if(j==b.length()){
				cout<<i-b.length()<<endl;
			}
		}
		else{
			if(j==0)
				i++;
			else
				j=pa[j-1];
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll n;
	while(sfd(n)!=EOF){
		string b,a;
		cin>>b>>a;
		kmp(a,b);
		cout<<endl;
	}
}