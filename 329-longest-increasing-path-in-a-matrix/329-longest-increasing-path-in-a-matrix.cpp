class Solution {
public:
    int dp[201][201];
    
    int dfs(vector<vector<int>>& mat,int i,int j, int pre){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || pre>=mat[i][j])
            return 0;
        
        if(dp[i][j]) return dp[i][j];
        
        int l=dfs(mat,i-1,j,mat[i][j]);
        int r=dfs(mat,i,j-1,mat[i][j]);
        int u=dfs(mat,i+1,j,mat[i][j]);
        int d=dfs(mat,i,j+1,mat[i][j]);
        
        return dp[i][j]=max({l,r,u,d})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int maxv=0;
        int n=mat.size(), m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxv=max(maxv,dfs(mat,i,j,-1));
            }
        }
        
        return maxv;
    }
};