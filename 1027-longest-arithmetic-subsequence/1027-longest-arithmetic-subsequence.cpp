class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        vector<unordered_map<int,int>> dp(n);
        int ans=2;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff=nums[j]-nums[i];
                
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]=max(dp[i][diff], dp[j][diff]+1);
                    ans=max(ans, dp[i][diff]);
                }
                
                else{
                    dp[i][diff]=2;
                }
               
            }
            
        }
        
        return ans;
    }
};