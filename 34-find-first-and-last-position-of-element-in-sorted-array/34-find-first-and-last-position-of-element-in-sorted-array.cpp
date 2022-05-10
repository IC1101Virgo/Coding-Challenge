class Solution {
public:
    
    int bs1(vector<int>& nums, int t,int lo, int hi, int r){
        while(lo<=hi){
            int mid=lo+hi-lo/2;
            
            if(nums[mid]==t){
                r=mid;
                return bs1(nums,t,lo,mid-1,r);
            }
            
            else if(nums[mid]>t)
                hi=mid-1;
            
            else lo=mid+1;
        }
        
        return r;
    }
    
    int bs2(vector<int>& nums, int t,int lo, int hi, int l){
        while(lo<=hi){
            int mid=lo+hi-lo/2;
            
            if(nums[mid]==t){
                l=mid;
                return bs1(nums,t,mid+1,hi,l);
            }
            
            else if(nums[mid]>t)
                hi=mid-1;
            
            else lo=mid+1;
        }
        
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int t) {
        int n=nums.size();
        
       int r=bs1(nums,t,0,n-1,-1);
        int l=bs2(nums,t,0,n-1,-1);
        
        
        return {r,l};
    }
};