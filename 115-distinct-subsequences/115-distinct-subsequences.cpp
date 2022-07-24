class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[0][j]=0;
                
                dp[i][0]=1;
            }
        }
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
                
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        
        return dp[n][m];
        
    }
};