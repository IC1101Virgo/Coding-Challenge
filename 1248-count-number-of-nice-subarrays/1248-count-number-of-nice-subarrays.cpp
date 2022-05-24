class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int n=nums.size();
        unordered_map<int,int> mp;
        int cnt=0;
        int sum=0;
        
        for(int i=0;i<n;i++){
           sum+=(nums[i]%2);
            if(sum==k) cnt++;
            
            if(mp.find(sum-k)!=mp.end())
                cnt+=mp[sum-k];
            
            mp[sum]++;
        }
        
        return cnt;
    }
};