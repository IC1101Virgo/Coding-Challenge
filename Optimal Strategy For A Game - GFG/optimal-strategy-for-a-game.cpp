// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long helper(int arr[], int i, int j, vector<vector<long long>> &dp ){
       
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(i+1==j)
        return dp[i][j]=max(arr[i],arr[j]);
        
        else {
            int a=arr[i]+min(helper(arr,i+1,j-1,dp),helper(arr,i+2,j,dp));
            int b=arr[j]+min(helper(arr,i,j-2,dp),helper(arr,i+1,j-1,dp));
            
            return dp[i][j]=max(a,b);
        }
        
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        
        return helper(arr,0,n-1,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends