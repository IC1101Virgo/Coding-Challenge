class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, int ind, vector<vector<int>> &res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            helper(nums,ind+1,res);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0,res);
        return res;
    }
};