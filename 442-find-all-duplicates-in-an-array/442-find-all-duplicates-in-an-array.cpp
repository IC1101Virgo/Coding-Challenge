class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(auto n:nums){
           if(nums[abs(n)-1]>0) 
               nums[abs(n)-1]*=-1;
            
            else res.push_back(abs(n));
        }
        
        return res;
    }
};