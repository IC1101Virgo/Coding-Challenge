class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
      int c=0;
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j] && (i*j)%k==0)
                {
                    c++;
                }
            }
        }
        return c;
    }
};