// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	      vector<int> dp(n+1,0);
    dp[0] = arr[0];
    int maxi = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = arr[i];
        int temp = 0; 
        for(int j=0;j<i;j++) {
            if(arr[j] < arr[i]) {
                temp = max(temp,dp[j]);
            }
        }
        dp[i] = temp+dp[i];
        maxi = max(maxi,dp[i]);
    }
    return maxi;
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends