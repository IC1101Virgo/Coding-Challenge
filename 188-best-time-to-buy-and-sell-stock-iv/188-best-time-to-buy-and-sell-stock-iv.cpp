class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        
        if(n==0||n==1)
            return 0;
        
        if(k>n)
            k=n;
        
        vector<vector<int>> dp(k+1,vector(n,0));
        
        for(int i=1;i<=k;i++){
            int diff=INT_MIN;
            for(int j=1;j<n;j++){
                diff=max(diff,dp[i-1][j-1]-p[j-1]);
                dp[i][j]=max(dp[i][j-1],diff+p[j]);
            }
        }
        
        return dp[k][n-1];
    }
};