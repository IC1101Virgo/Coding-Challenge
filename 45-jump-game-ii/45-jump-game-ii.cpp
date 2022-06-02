class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        int curr=0;
        int count=0;
        int next=0;
        
        for(int i=0;i<=curr;i++){
            if(i==n-1)
                return count;
            
            next=max(next,nums[i]+i);
            
            if(i==curr){
                count++;
                curr=next;
            }
        }
        
        return -1;
    }
};