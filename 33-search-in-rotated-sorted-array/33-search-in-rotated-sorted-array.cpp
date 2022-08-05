class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]<target) l=mid+1;
            
            else r=mid-1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        int lo=0, hi=n-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(nums[mid]>=nums[hi]) lo=mid+1;
            
            else hi=mid;
        }
        
        int pivot=hi;
        
        return max(bs(nums,target,0,pivot-1),bs(nums,target,pivot,n-1));
    }
};