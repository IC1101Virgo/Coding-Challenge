class Solution {
public:
    int dp[5000][2];
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        dp[0][1]=0;
        dp[0][0]=-prices[0];
        dp[1][0]=max(-prices[0],-prices[1]);
        dp[1][1]=max(0,-prices[0]+prices[1]);
        for(int i=2; i<prices.size(); i++){
            dp[i][0]=max(dp[i-2][1]-prices[i], dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+prices[i], dp[i-1][1] );
        }
        return dp[prices.size()-1][1];
    }
};
