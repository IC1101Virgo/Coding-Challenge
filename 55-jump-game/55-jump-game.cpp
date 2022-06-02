class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        
        int curr=nums[0];
        
        for(int i=0;i<=curr;i++){
            if(i==n-1)
                return 1;
            
            curr=max(curr,i+nums[i]);
        }
        
        return 0;
    }
};