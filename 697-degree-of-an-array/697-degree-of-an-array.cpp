class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        
        int degree=0;

        for(auto x: mp){
            int size=x.second.size();
            degree=max(degree, size);
        }
        
        int min_len=INT_MAX;
        
        for(auto x:mp){
            if(x.second.size()==degree){
            int mini= *min_element(x.second.begin(),x.second.end());
            int maxi= *max_element(x.second.begin(),x.second.end());
                
                min_len= min(min_len, maxi-mini+1);
                }
        }
        
        return min_len;
    }
};