class Solution {
public:
    int helper(vector<vector<int>>& t,vector<vector<int>>& dp,int i, int j){
        int n=t.size();
        
        if(i>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        else{
        int a=t[i][j]+helper(t,dp,i+1,j), b=t[i][j]+helper(t,dp,i+1,j+1);
        
        return dp[i][j]=min(a,b);
        }
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return helper(t,dp,0,0);
    }
};