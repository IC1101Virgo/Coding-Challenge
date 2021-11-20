class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
	while(start < end){
		int mid = start + (end - start)/2;
		int temp = mid % 2 == 0 ? mid+1 : mid-1;
		if(nums[mid] == nums[temp]) start = mid + 1;
		else end = mid;
	}
	return nums[start];
    }
};
