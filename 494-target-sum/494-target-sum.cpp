class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
       int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum<abs(t) || (sum+t)%2!=0)
            return 0;
        
        int tar=(sum+t)/2;
        
        vector<int>dp(tar+1,0);
        
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=tar;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        
        return dp[tar];
    }
};