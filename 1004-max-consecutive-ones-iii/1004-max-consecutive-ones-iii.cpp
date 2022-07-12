class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        
        int ans=INT_MIN,i=0,j=0;
        
        while(j<n){
            if(k>=0 && nums[j++]==0)
                k--;
            
            if(k<0 && nums[i++]==0)
                k++;
            
            ans=max(ans,j-i);
        }
        
        return ans;
    }
};