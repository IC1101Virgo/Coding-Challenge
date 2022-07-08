class Solution {
public:
    int fib(int n) {
        
       int dp[31];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
        
    }
};