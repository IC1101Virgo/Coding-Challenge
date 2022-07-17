class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;
        deque<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            if(!q.empty() && q.front().second<=i-k)
                q.pop_front();
            
            while(!q.empty() && q.back().first<nums[i])
                q.pop_back();
            
            q.push_back({nums[i],i});
            
            if(i+1-k>=0)
                v.push_back(q.front().first);
            
        }
        
        return v;
    }
};