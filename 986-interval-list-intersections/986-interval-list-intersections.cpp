class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> res;
        
        int n=f.size();
        int m=s.size();
        int i=0,j=0;
        
       while(i<n && j<m){
            int l=max(f[i][0],s[j][0]);
            int u=min(f[i][1],s[j][1]);
           
           if(l<=u)
            res.push_back({l,u});
            
            if(f[i][1]<s[j][1])
                i++;
           else j++;
        }
        
        return res;
    }
};