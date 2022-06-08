// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  int helper(int A[], int n, int B){
     
    
    vector<vector<int>> dp(n+1,vector<int>(B+1,0));
    
     for(int i=0;i<=n;i++){
        for(int j=0;j<=B;j++){
            if(i==0||j==0)
            dp[i][j]=0;
        }
     }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=B;j++){
           
            
             if(A[i-1]<=j)
            dp[i][j]=max(A[i-1]+dp[i-1][j-A[i-1]],dp[i-1][j]);
            
            else dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][B];
}
	int minDifference(int A[], int n)  { 
	    // Your code goes here
	    
    
    int sum=0;
    
    for(int i=0;i<n;i++)
    sum+=A[i];
    
    return sum-(2*helper(A,n,sum/2));
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends