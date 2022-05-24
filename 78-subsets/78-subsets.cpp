class Solution {
public:
    void helper(vector<int> &nums, int ind, vector<int> vec, vector<vector<int>> &res){
        if(ind==nums.size()){
            res.push_back(vec);
                return;
        }
        
        vec.push_back(nums[ind]);
        helper(nums,ind+1,vec,res);
        vec.pop_back();
        helper(nums,ind+1,vec,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> res;
        
        int n=nums.size();
        
        helper(nums,0,vec,res);
        
        return res;
        
    }
};