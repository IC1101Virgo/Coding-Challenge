class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newi) {
        vector<vector<int>> res;
        
        int i=0;
        
        int n=intervals.size();
        
        while(i<n && intervals[i][1]<newi[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        while(i<n && intervals[i][0]<=newi[1]){
            newi[0]=min(newi[0],intervals[i][0]);
            newi[1]=max(newi[1],intervals[i][1]);
            i++;
        }
        
        res.push_back(newi);
        
        
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};