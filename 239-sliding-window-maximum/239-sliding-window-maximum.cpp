class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        deque<pair<int,int>> dq;
        
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            while(!dq.empty() && dq.back().first<nums[i])
                dq.pop_back();
            
            if(!dq.empty() && dq.front().second<i+1-k)
                dq.pop_front();
            
            dq.push_back({nums[i],i});
            
            if(i+1-k>=0)
                ans.push_back(dq.front().first);
        }
        
        return ans;
    }
};