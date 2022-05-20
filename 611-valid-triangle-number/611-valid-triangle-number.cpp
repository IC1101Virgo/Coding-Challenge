class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int ans=0;
        
        for(int i=n-1;i>=0;i--){
            int left=0, right=i-1;
            
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    ans+=right-left;
                    right--;
                }
                
                else left++;
            }
        }
        
        return ans;
    }
};