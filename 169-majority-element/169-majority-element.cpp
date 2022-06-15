class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
       /* int count=0, ele=0;
        
        for(int i=0;i<n;i++){
            
            if(count==0)
                ele=nums[i];
            
            if(ele==nums[i])
                count++;
            
            else count--;
            
        }
        
        return ele; */
        
        sort(nums.begin(),nums.end());
        
        return nums[n/2];
    }
};