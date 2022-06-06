class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        if(n<=1)
            return 0;
        
        int dp[n];
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            if(prices[i-1]<prices[i])
                dp[i]=dp[i-1]+prices[i]-prices[i-1];
            
            else dp[i]=dp[i-1];
        }
        
        return dp[n-1];
        
    }
};