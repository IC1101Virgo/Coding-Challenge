class Solution {
public:
    void helper(vector<int> &nums, vector<int> v,vector<vector<int>> &res, int ind){
        
            res.push_back(v);
         
        
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            
            v.push_back(nums[i]);
            helper(nums,v,res,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        vector<vector<int>> res;
        
        helper(nums,v,res,0);
        return res;
    }
};