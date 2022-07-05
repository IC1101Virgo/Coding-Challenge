class Solution {
public:
    int dp[13][10001];
    int helper(vector<int>& coins, int n, int amount){
        if(n<=0)
            return dp[n][amount]=INT_MAX-1;
        
        if(amount==0)
            dp[n][amount]=0;
        
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        if(coins[n-1]<=amount)
            return dp[n][amount]=min(1+helper(coins,n,amount-coins[n-1]),helper(coins,n-1,amount));
        
        else return dp[n][amount]=helper(coins,n-1,amount);
        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        
        int ans= helper(coins,n,amount);
        
        return ans==INT_MAX-1?-1:ans;
    }
};