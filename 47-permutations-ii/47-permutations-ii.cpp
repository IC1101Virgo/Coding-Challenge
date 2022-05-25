class Solution {
public:
   // set<vector<int>> ans;
    vector<vector<int>>res;
    void helper(vector<int> nums, int ind){
      if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
           if(nums[i]!=nums[ind]){
               swap(nums[i],nums[ind]);
               helper(nums, ind+1);
           }
            
            else if(i==ind){
                helper(nums,ind+1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         helper(nums,0);
        return res;
    }
};