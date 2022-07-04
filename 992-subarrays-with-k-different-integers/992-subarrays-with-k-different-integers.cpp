class Solution {
public:
    int helper(vector<int> &nums, int k){
        unordered_map<int,int> freq;
        int count=0;
        int n=nums.size();
        
        int i=0,j=0;
        
        while(i<n && j<n){
            if(k>=0){
                freq[nums[i]]++;
                
                if(freq[nums[i]]==1)
                    k--;
                
                i++;
            }
            
            while(k<0){
                freq[nums[j]]--;
                
                if(freq[nums[j]]==0)
                    k++;
                
                j++;
            }
            
            count+=(i-j+1);
        }
        
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k)-helper(nums,k-1);
    }
};