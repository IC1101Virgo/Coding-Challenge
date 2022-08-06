class Solution {
public:
    typedef pair<int,int> pip;
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        for(auto x:nums){
            mp[x]++;
        }
        
        priority_queue<pip> pq;
        
        for(auto x:mp){
            pq.push({-x.second,x.first});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++)
                ans.push_back(pq.top().second);
            
            pq.pop();
        }
        
        return ans;
    }
};