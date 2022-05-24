// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  #define mod 1000000007
    long long int numberOfPaths(int m, int n){
        // code here
        
         vector<vector<long long int>> dp(n, vector<long long int> (m,0));
         //dp[0][0]=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0|| j==0)
                    dp[i][j]=1;
                
                else dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
                
            }
        }
        
        
        
        return dp[n-1][m-1]%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends