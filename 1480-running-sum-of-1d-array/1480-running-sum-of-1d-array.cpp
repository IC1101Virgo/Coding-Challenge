class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> suf(n,0);
        suf[0]=nums[0];
        
        for(int i=1;i<n;i++)
            suf[i]=suf[i-1]+nums[i];
        
        return suf;
    }
};