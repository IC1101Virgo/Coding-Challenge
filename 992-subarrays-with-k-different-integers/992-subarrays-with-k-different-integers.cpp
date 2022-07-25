class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int,int> m;
        int cnt=0;
        int i=0,j=0;
        
        while(i<n && j<n){
            if(k>=0){
                m[nums[i]]++;
                
                if(m[nums[i]]==1)
                    k--;
                
                i++;
            }
            
            while(k<0){
                m[nums[j]]--;
                
                if(m[nums[j]]==0)
                k++;
                
                j++;
                
            }
            
            cnt+=(i-j+1);
        }
        
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        
        if(n==0)
            return n;
        
        return (helper(nums,k)-helper(nums,k-1));
    }
};