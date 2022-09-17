class Solution {
public:
    int coinChange(vector<int>& coins, int v) {
        int n=coins.size();
        
         vector<vector<int>> dp(n+1, vector<int>(v+1));
	    
	     for(int j=1;j<=v;j++)
        {
            dp[0][j]=INT_MAX-1;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=v; j++){
	            if(coins[i-1]<=j){
	                dp[i][j] = min( 1 + dp[i][j-coins[i-1]], dp[i-1][j]);
	            }
	            
	            else dp[i][j]= dp[i-1][j];
	        }
	    }
	    
	    return dp[n][v]==INT_MAX-1? -1: dp[n][v];
	    
    }
};