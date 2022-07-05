class Solution {
public:
    int helper(int n, int k, vector<vector<int>> &dp){
        if(k==1)
            return n;
        
        if(n==0||n==1)
            return n;
        
        if(dp[k][n]!=-1)
            return dp[k][n];
        
        int lo=0, hi=n;
        int mn=INT_MAX;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            int left=helper(mid-1,k,dp);
            int right=helper(n-mid,k-1,dp);
            
            int temp=1+max(left,right);
            
            if(left<right)
                lo=mid+1;
            
            else hi=mid-1;
            
            mn=min(mn,temp);
        }
        
        return dp[k][n]=mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        
        return helper(n,k,dp);
    }
};