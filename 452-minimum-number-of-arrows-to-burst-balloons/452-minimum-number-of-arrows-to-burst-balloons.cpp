class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> vp;
        int n=points.size();
        
        for(int i=0;i<n;i++){
            vp.push_back({points[i][1],points[i][0]});
        }
        
        sort(vp.begin(),vp.end());
        
        int ans=1, curr=vp[0].first;
        
        for(int i=1;i<n;i++){
            if(curr<vp[i].second){
                ans++;
                curr=vp[i].first;
            }
        }
        
        return ans;
    }
};