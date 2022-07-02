// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int s[], int n, int m) {

        // code here.
        vector<vector<long long >> dp(n+1,vector<long long>(m+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)
                dp[i][j]=0;
                
                else if(j==0)
                dp[i][j]=1;
                
                else if(s[i-1]<=j)
                dp[i][j]=dp[i][j-s[i-1]]+dp[i-1][j];
                
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends