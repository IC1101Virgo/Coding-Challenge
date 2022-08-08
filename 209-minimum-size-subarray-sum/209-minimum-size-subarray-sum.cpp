class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        
        int i=0, j=0;
        int min_len=INT_MAX;
        int sum=0;
        
        while(j<n){
            while(j<n && sum<target){
                sum+=nums[j++];
            }
            
            while(sum>=target){
             min_len=min(min_len, j-i);
                sum-=nums[i++];
            }
            
            
            
        }
        
        if(min_len==INT_MAX)
            return 0;
        
        else return min_len;
    }
};