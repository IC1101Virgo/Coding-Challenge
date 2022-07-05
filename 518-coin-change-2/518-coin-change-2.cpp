class Solution {
public:
    int change(int amt, vector<int>& coin) {
         int n=coin.size();
        
        vector<vector<int>> dp(n+1,vector<int>(amt+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amt;j++){
                dp[i][0]=1;
                dp[0][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amt;j++){
                if(coin[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][amt];
    }
};