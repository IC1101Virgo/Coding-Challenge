class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &res, vector<int> temp, int i){
        int n=nums.size();
        
        if(i==n){
            res.push_back(temp);
            return; 
        }
        
        temp.push_back(nums[i]);
        helper(nums,res,temp,i+1);
        temp.pop_back();
        helper(nums,res,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> res;
        
        helper(nums,res,{},0);
        
        return res;
    }
};