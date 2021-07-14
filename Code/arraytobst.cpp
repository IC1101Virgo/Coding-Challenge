class Solution {
public:
    void helper(vector<int> &nums,vector<int> &ans,int start,int end){
        if(start>end)
        return;
        int mid=start+(end-start)/2;
        ans.push_back(nums[mid]);
        helper(nums,ans,start,mid-1);
        helper(nums,ans,mid+1,end);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> ans;
        int n=nums.size();
        helper(nums,ans,0,n-1);
        return ans;
        
    }
};
