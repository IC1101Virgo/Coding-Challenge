class Solution {
public:
    int helper(vector<int> &nums, int k){
        int i=0,j=0, count=0;
        const int n=nums.size();
        unordered_map<int,int> freq;
        
        while(j<n){
            if(k>=0){
                ++freq[nums[j]];
                
                if(freq[nums[j]]==1)
                    --k;
                
                ++j;
            }
            
            while(k<0){
                --freq[nums[i]];
                
                if(freq[nums[i]]==0)
                    ++k;
                
                ++i;
            }
            
            count+=(j-i+1);
        }
        
        return count;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};