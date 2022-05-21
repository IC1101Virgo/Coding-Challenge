class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
        
        int count=0;
        int eq=1;
        
        for(int i=0;i<n;i++){
            if(i<n-1 && nums[i]==nums[i+1])
                eq++;
            
            else{
                nums[count]=nums[i];
                count++;
                
                if(eq>=2){
                    nums[count]=nums[i];
                    count++;
                }
                
                eq=1;
            }
        }
        
        return count;
    }
};