class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> v;
        vector<vector<int>> res;
        
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        
        for(auto p:points){
            int x=p[0]*p[0]+p[1]*p[1];
            pq.push({x,{p[0],p[1]}});
        }
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};