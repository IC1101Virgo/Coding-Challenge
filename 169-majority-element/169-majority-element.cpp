class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int count=1;
        int ele=nums[0];
        
        for(int i=1;i<n;i++){
            if(count<=0)
                ele=nums[i];
            
            nums[i]==ele?count++:count--;
        }
        
        return ele;
        
    }
};