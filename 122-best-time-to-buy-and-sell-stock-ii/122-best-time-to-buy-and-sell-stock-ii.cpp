class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        vector<int> dp(n,0);
        
        for(int i=1;i<n;i++){
            if(p[i]>p[i-1])
                dp[i]=dp[i-1]+p[i]-p[i-1];
            
            else dp[i]=dp[i-1];
        }
        
        return dp[n-1];
    }
};