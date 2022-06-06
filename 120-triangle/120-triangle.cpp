class Solution {
public:
    
    int helper(vector<vector<int>>& tri, int i, int j, vector<vector<int>> &dp){
        if(i==tri.size())
            return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        else
           return dp[i][j]=tri[i][j]+min(helper(tri,i+1,j,dp),helper(tri,i+1,j+1,dp));
        
        
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int h=tri.size();
        int n=h;
        
        vector<vector<int>> dp(h,vector<int>(n,-1));
        
        return helper(tri,0,0,dp);
        
        
    }
};