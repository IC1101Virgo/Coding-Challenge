class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i]=mat[i][j];
            }
        }
        
        return ans;
    }
};