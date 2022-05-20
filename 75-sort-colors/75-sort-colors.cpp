class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n=nums.size();
        
        int i=0, j=0, k=n-1;
        
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i++],nums[j]);
            }
            
            if(nums[j]==2){
                swap(nums[j],nums[k--]);
            }
            
            else j++;
        }
        
        return;
    }
};