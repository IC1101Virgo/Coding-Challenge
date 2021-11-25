class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_curr=0, max_glo=nums[0];
        
        for(int i=0;i<nums.size();i++){
            max_curr=max(nums[i],max_curr+nums[i]);
            max_glo=max(max_glo,max_curr);
        }
        
        return max_glo;
    }
};
