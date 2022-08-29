class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
         vector<int> v(2,0);
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(t-nums[i])!=mp.end()){
                v[0]=i;
                v[1]=mp[t-nums[i]];
            }
            
            else
            mp[nums[i]]=i;
        }
        
        return v;
    }
};