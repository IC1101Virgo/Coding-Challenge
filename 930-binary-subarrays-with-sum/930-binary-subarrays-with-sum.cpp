class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n=nums.size();
        unordered_map<int,int> m;
        int sum=0;
        int ans=0;
        
        for(int i=0; i<n; i++){
            sum+=nums[i];
            
            if(sum==goal)
            ans++;
            
            if(m.find(sum-goal)!=m.end()){
                ans+=m[sum-goal];
            }
            
          // else if(m.find(sum)==m.end())
                m[sum]++;
        }
        
        return ans;
    }
};