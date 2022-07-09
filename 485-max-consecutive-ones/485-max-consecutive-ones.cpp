class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        
        int ones=0,ans=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans=max(ans,ones);
                ones=0;
            }
            
           else ones++;
        }
        
        return max(ans,ones);
    }
};