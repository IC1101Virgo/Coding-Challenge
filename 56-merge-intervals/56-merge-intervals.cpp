class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        
        for(int i=0;i<n;i++){
            if(i==n-1)
                res.push_back(intervals[i]);
            
            else if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i+1][1],intervals[i][1]);
            }
            
            else res.push_back(intervals[i]);
        }
        
        return res;
    }
};