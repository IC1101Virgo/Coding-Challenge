class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(20,0);
        
        dp[0]=1;
        
        dp[1]=1;
        dp[2]=2;
        
        if(n<3)
            return dp[n];
        
         for(int i=3;i<=n;i++){
            int temp=0;
            for(int j=0;j<i;j++){
                temp+= dp[j]*dp[i-j-1];
            }
            dp[i]=temp;
        }
        
        return dp[n];
    }
};