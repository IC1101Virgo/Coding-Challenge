class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, n = nums.size();
    
        int temp = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] < temp) end = i;
            temp = max(temp, nums[i]);
        }

        temp = nums[n - 1];
        for(int i = n - 1; i >= 0; i--) {
            if(temp < nums[i]) start = i;
            temp = min(temp, nums[i]);
        }

        return (start == -1) ? 0 : (end - start) + 1;
    }
};