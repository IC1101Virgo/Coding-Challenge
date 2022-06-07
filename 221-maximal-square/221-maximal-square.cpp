class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(mat[i-1][j-1]=='1')
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                
                
                ans=max(ans,dp[i][j]);
                
            }
        }
        
        return ans*ans;
    }
};