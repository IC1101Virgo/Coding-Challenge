class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0, next=0; i<n; i++){
            if(nums[i]!=0)
                swap(nums[i], nums[next++]);
        }
    }
};