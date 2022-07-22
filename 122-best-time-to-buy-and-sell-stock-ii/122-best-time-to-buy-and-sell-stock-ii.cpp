class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        vector<int> dp(n,0);
        
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            if(p[i-1]<p[i]){
                dp[i]=dp[i-1]+p[i]-p[i-1];
            }
            
            else dp[i]=dp[i-1];
        }
        
        return dp[n-1];
    }
};