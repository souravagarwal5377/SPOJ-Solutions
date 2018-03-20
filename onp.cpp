#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll reverse(ll n){
	ll i,r=0;
	while(n>0){
		i=n%10;
		r=r*10+i;
		n/=10;
	}
	return r;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
	ll t;
	map<char,ll> p;
	p['(']=0;
	p['+']=1;
	p['-']=2; p['*']=3; p['/']=4; p['^']=5; p[')']=6;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<char> op;
		for(ll i=0;i<s.length();i++){
			if(s[i]>=97&&s[i]<=122)
				printf("%c",s[i] );
			else if(s[i]=='(')
				op.push(s[i]);
			else if(s[i]==')'){
				while(op.top()!='(')
				{
					char x=op.top(); 
					op.pop();
					printf("%c", x);
				}
				op.pop();
			}
			else 
			{
				if(op.empty()==true||p[s[i]]>p[op.top()])
					op.push(s[i]);
				else{
					while(!op.empty()&&p[s[i]]>p[op.top()]){
						char x=op.top();
						printf("%c",x );
					}
					op.push(s[i]);
				}
			}
		}
		while(!op.empty())
		{
			char x=op.top();
			printf("%c",x );
			op.pop();
		}
		cout<<endl;
	}
}