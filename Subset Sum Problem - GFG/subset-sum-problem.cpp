// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>A, int B){
        int n=A.size();
        vector<vector<int>>dp(n+1,vector<int>(B+1,0));

    for(int i=0;i<=n;i++){
       for(int j=0;j<=B;j++){
           if(i==0)
           dp[i][j]=0;
           if(j==0)
           dp[i][j]=1;
       }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=B;j++){
            if(A[i-1]<=j)
            dp[i][j]=max(dp[i-1][j-A[i-1]], dp[i-1][j]);
            
            else 
            dp[i][j]=dp[i-1][j];
            
        }
    }
    
    return dp[n][B];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends