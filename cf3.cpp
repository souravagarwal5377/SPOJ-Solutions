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
    if(a+b+c+d<=50){
    	ll i;
    	cout<<"1 "<<a+b+c+d<<endl;
    	for(i=0;i<4;i++){
    		for(ll j=0;j<p[i].first;j++)
    			cout<<p[i].second;
    	}
    	cout<<endl;
    	return 0;
    }
    ll x=(a+b+c+d)/50;
    if((a+b+c+d)%50!=0)
    	x++;
    ll i,j;
    ll row=0,col=0;
    char mat[101][101];
    cout<<x<<" "<<"50\n";
    int cnt=0;
    for(i=0;i<4;i++){
		for(j=0;j<p[i].first;j++){
			mat[row][col]=p[i].second;
			cnt++;
			col++;
			if(cnt==50){
				mat[row][col]='\0';
				row++;
				cnt=0;
				col=0;
			}
		}
    }
    while(cnt<50){
    	if(mat[row-1][col]=='A'){
    		if(mat[row][col-1]=='B'){
    			mat[row][col++]='C';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='C'){
    			mat[row][col++]='D';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='A'){
    			mat[row][col++]='C';
    			cnt++;
    		} 
    		else if(mat[row][col-1]=='D'){
    			mat[row][col++]='C';
    			cnt++;
    		}
    	}
    	else if(mat[row-1][col]=='B'){
    		if(mat[row][col-1]=='B'){
    			mat[row][col++]='C';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='C'){
    			mat[row][col++]='D';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='A'){
    			mat[row][col++]='C';
    			cnt++;
    		} 
    		else if(mat[row][col-1]=='D'){
    			mat[row][col++]='C';
    			cnt++;
    		}
    	}
    	else if(mat[row-1][col]=='C'){
    		if(mat[row][col-1]=='B'){
    			mat[row][col++]='A';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='C'){
    			mat[row][col++]='D';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='A'){
    			mat[row][col++]='B';
    			cnt++;
    		} 
    		else if(mat[row][col-1]=='D'){
    			mat[row][col++]='B';
    			cnt++;
    		}
    	}
    	else if(mat[row-1][col]=='D'){
    		if(mat[row][col-1]=='B'){
    			mat[row][col++]='C';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='C'){
    			mat[row][col++]='A';
    			cnt++;
    		}
    		else if(mat[row][col-1]=='A'){
    			mat[row][col++]='C';
    			cnt++;
    		} 
    		else if(mat[row][col-1]=='D'){
    			mat[row][col++]='C';
    			cnt++;
    		}
    	} 
    }
    mat[row][col]='\0';
    for(i=0;i<x;i++)
    	cout<<mat[i]<<endl;
    cout<<endl;
}