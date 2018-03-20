#include<bits/stdc++.h>
#define pf printf
using namespace std;
int a[50000];
int n;
inline void scani(int &x)
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
    int leftsum;    //maxsum for the node if sum begins from beginning of lower limit
    int rightsum;   //maxsum possible if sum ends at the upperlimit
    int maxsum;     //maxsum for the range
    int sum;         //sum of entire range
};
struct node st[1000000];   //segment tree;
void maketree(int l,int u,int pos){
    if(l==u){
        st[pos].leftsum=st[pos].rightsum=st[pos].maxsum=st[pos].sum=a[l];  //leafnode
        return;
    }
    int m=l+(u-l)/2;
    maketree(l,m,2*pos+1);
    maketree(m+1,u,2*pos+2);
    st[pos].sum=st[2*pos+1].sum+st[2*pos+2].sum;
    st[pos].leftsum=max(st[2*pos+1].leftsum,st[2*pos+1].sum+st[2*pos+2].leftsum);
    st[pos].rightsum=max(st[2*pos+2].rightsum,st[2*pos+2].sum+st[2*pos+1].rightsum);
    st[pos].maxsum=max(st[2*pos+1].maxsum,max(st[2*pos+2].maxsum,max(st[pos].sum,max(st[pos].leftsum,max(st[pos].rightsum,(st[2*pos+1].rightsum+st[2*pos+2].leftsum))))));
    //above statement calculates max of leftsun,rightsum,totalsum,leftmaxsum,rightmaxsum,right of leftsum+left of right sum
}
node* query(int l,int u,int pos,int ql,int qu){
    if(l>=ql&&u<=qu){
        return(&st[pos]);
    }
    if(ql>u||qu<l){
        struct node* nn=(node *)malloc(sizeof(node));
        nn->leftsum=nn->maxsum=nn->rightsum=nn->sum=-1000000;
        return nn;
    }
    int m=l+(u-l)/2;
    node* lef=query(l,m,2*pos+1,ql,qu);
    node* rig=query(m+1,u,2*pos+2,ql,qu);
    struct node* x=(node *)malloc(sizeof(node));
    x->sum=lef->sum+rig->sum;
    x->leftsum=max(lef->leftsum,lef->sum+rig->leftsum);
    x->rightsum=max(rig->rightsum,rig->sum+lef->rightsum);
    x->maxsum=max(lef->maxsum,max(rig->maxsum,max(x->sum,max(lef->leftsum,max(rig->rightsum,(lef->rightsum+rig->leftsum))))));
    return x;
}
int main()
{
    int m;
    scani(m);
    int i;
    for(i=0;i<m;i++)
        scani(a[i]);
    //int n=sizetree(m);
    //cout<<n<<endl;
    maketree(0,m-1,0);
    int q;
    scani(q);
    while(q--){
        int x,y;
        scani(x);scani(y);
        node*  ans=query(0,m-1,0,x-1,y-1);
        pf("%d\n",ans->maxsum);
    }
}

