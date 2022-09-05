class Solution {
public:
    int bt(vector<int> nums,int target,vector<int>&cache) 
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(cache[target]!=-1)
            return cache[target];
        int res=0;
        for(int i:nums)
        {
            res+=bt(nums,target-i,cache);
        }
        return cache[target]=res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target+1,-1);
        
        return bt(nums,target,cache);
    }
};