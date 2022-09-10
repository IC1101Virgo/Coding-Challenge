class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        
        set<int> s;
        
        for(auto x:nums)
            s.insert(x);
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(s.find(nums[i]-1)!=s.end())
                continue;
            
            else{
                int count=0;
                int temp=nums[i];
                
                while(s.find(temp)!=s.end()){
                    temp++;
                    count++;
                }
                
                ans=max(ans,count);
            }
        }
        
        return ans;
    }
};