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
struct node{
	int d[3]; 	//3n //3n+1	//3n+2
};
node st[4000005];
int lazy[4000005]={0};
void maketree(int l,int u,int pos){
	if(l==u){
		st[pos].d[0]=1;
		st[pos].d[1]=0;
		st[pos].d[2]=0;
		return;
	}
	int m=l+(u-l)/2;
	maketree(l,m,2*pos+1);
	maketree(m+1,u,2*pos+2);
	st[pos].d[0]=st[2*pos+1].d[0]+st[2*pos+2].d[0];
	st[pos].d[1]=st[2*pos+1].d[1]+st[2*pos+2].d[1];
	st[pos].d[2]=st[2*pos+1].d[2]+st[2*pos+2].d[2];
}
void update(int l,int u,int ql,int qu,int pos){
	if(lazy[pos]%3==1){
		int temp=st[pos].d[1];
		st[pos].d[1]=st[pos].d[0];
		st[pos].d[0]=st[pos].d[2];
		st[pos].d[2]=temp;
		if(l!=u){
			lazy[2*pos+1]++;
			lazy[2*pos+2]++;
		}
		lazy[pos]=0;
	}
	if(lazy[pos]%3==2){
		int temp=st[pos].d[2];
		st[pos].d[2]=st[pos].d[0];
		st[pos].d[0]=st[pos].d[1];
		st[pos].d[1]=temp;
		if(l!=u){
			lazy[2*pos+1]+=2;
			lazy[2*pos+2]+=2;
		}
		lazy[pos]=0;
	}
	if(l>=ql&&u<=qu){
		int temp=st[pos].d[1];
		st[pos].d[1]=st[pos].d[0];
		st[pos].d[0]=st[pos].d[2];
		st[pos].d[2]=temp;
		//cout<<l<<" "<<u<<" "<<st[pos].d[0]<<endl;
		lazy[2*pos+1]++;
		lazy[2*pos+2]++;
		return;
	}
	if(l>qu||ql>u)
		return;
	int m=l+(u-l)/2;
	update(l,m,ql,qu,2*pos+1);
	update(m+1,u,ql,qu,2*pos+2);
	st[pos].d[0]=st[2*pos+1].d[0]+st[2*pos+2].d[0];
	st[pos].d[1]=st[2*pos+1].d[1]+st[2*pos+2].d[1];
	st[pos].d[2]=st[2*pos+1].d[2]+st[2*pos+2].d[2];
	//cout<<l<<" "<<u<<" "<<st[pos].d[0]<<endl;
}
node* query(int l,int u,int ql,int qu,int pos){
	//lazy[pos]=lazy[pos]%3;
	if(lazy[pos]%3==1){
		int temp=st[pos].d[1];
		st[pos].d[1]=st[pos].d[0];
		st[pos].d[0]=st[pos].d[2];
		st[pos].d[2]=temp;
		if(l!=u){
			lazy[2*pos+1]++;
			lazy[2*pos+2]++;
		}
		lazy[pos]=0;
	}
	if(lazy[pos]%3==2){
		int temp=st[pos].d[2];
		st[pos].d[2]=st[pos].d[0];
		st[pos].d[0]=st[pos].d[1];
		st[pos].d[1]=temp;
		if(l!=u){
			lazy[2*pos+1]+=2;
			lazy[2*pos+2]+=2;
		}
		lazy[pos]=0;
	}
	if(l>=ql&&u<=qu){
		//cout<<l<<" "<<u<<" "<<st[pos].d[0]<<endl;
		return &st[pos];
	}
	if(l>qu||ql>u){
		struct node* tt=(node*)malloc(sizeof(node));
		tt->d[0]=0;
		tt->d[1]=0;
		tt->d[2]=0;
		return tt;
	}
	int m=l+(u-l)/2;
	node* left=query(l,m,ql,qu,2*pos+1);
	node* right=query(m+1,u,ql,qu,2*pos+2);	
	node* ans=(node*)malloc(sizeof(node));
	ans->d[0]=left->d[0]+right->d[0];
	ans->d[1]=left->d[1]+right->d[1];
	ans->d[2]=left->d[2]+right->d[2];
	//cout<<l<<" "<<u<<" "<<ans->d[0]<<endl;
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);	
    #endif 
	int n,q;
	sfd(n);sfd(q);
	maketree(0,n-1,0);
	int x,y,z;
	while(q--){
		sfd(x);sfd(y);sfd(z);
		if(x==0)
			update(0,n-1,y,z,0);
		else{
			node* ans=query(0,n-1,y,z,0);
			cout<<ans->d[0]<<endl;
		}
	}
}