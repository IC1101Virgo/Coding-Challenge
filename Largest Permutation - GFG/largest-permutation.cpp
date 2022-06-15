// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    void KswapPermutation(int A[], int n, int B)
    {
       
unordered_map<int,int> m;

for(int i=0; i<n; i++)
m[A[i]]=i;

for(int i=0; (i<n && B); i++)
{
if(A[i]!=n-i)
{
int index=m[n-i];
swap(A[i],A[index]);
m[A[i]]=i;
m[A[index]]=index;
B--;
}
}

return;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		Solution ob;
		ob.KswapPermutation(arr,n,k);
		for(int i=0;i<n;++i)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}

  // } Driver Code Ends