class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &res, vector<int> temp, int ind){
       
            res.push_back(temp);
            
        
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            helper(nums,res,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        helper(nums,res,{},0);
        
        return res;
    }
};