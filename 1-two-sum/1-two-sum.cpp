class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        unordered_map<int,int>m;
        int n=nums.size();
        
        
        
        for(int i=0;i<n;i++){
            
            if(m.find(target-nums[i])!=m.end()){
                v[0]=i;
                v[1]=m[target-nums[i]];
            }
            
           m[nums[i]]=i;
        }
        
        return v;
    }
};