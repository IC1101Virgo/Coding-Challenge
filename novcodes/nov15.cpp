class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), mx=0, ans=INT_MIN;
        vector<int> dp(n,0), parent(n,-1), sol;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 ||nums[j]%nums[i]==0) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            
             if(dp[i]>ans){
                    ans=dp[i];
                    mx=i;
                }
        }
        
        while(mx!=-1){
            sol.push_back(nums[mx]);
            mx=parent[mx];
        }
        
        return sol;
    }
};
