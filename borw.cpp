#include<bits/stdc++.h>
#define ll long long
#define sfd(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&x)
#define pf printf
using namespace std;
int GetCeilIndex(int arr[], vector<int> &T, int l, int r,
                 int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
vector<int> LongestIncreasingSubsequence(int arr[], int n)
{
    // Add boundary case, when array n is zero
    // Depend on smart pointers
 
    vector<int> tailIndices(n, 0); // Initialized with 0 
    vector<int> prevIndices(n, -1); // initialized with -1
 
    int len = 1; // it will always point to empty location
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[tailIndices[0]])
        {
            // new smallest value
            tailIndices[0] = i;
        }
        else if (arr[i] > arr[tailIndices[len-1]])
        {
            // arr[i] wants to extend largest subsequence
            prevIndices[i] = tailIndices[len-1];
            tailIndices[len++] = i;
        }
        else
        {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len-1, arr[i]);
 
            prevIndices[i] = tailIndices[pos-1];
            tailIndices[pos] = i;
        }
    }
 
    //cout << "LIS of given input" << endl;
    vector<int> v;
    for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i])
        v.push_back(arr[i]);
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    while(1){
        int n;
        cin>>n;
        if(n==-1)
            break;
        int i,a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        if(n<=3){
            cout<<"0\n";
            continue;
        }
        vector<int> lis=LongestIncreasingSubsequence(a,n);
        /*for(i=0;i<lis.size();i++)
            cout<<lis[i]<<" ";
        cout<<endl;*/
        int v[500];
        int j=0,k=0;
        for(i=0;i<n;i++){
            if(j<lis.size()&&a[i]==lis[j]){
                j++;
            }
            else
                v[k++]=a[i];
        }
        vector<int> lds=LongestIncreasingSubsequence(v,k);
        int ans=n-(lis.size()+lds.size());
        cout<<ans<<endl;
    }
}