class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(vector<vector<int>>& mat, int n, int m, int i, int j, vector<vector<int>>& dp){
        if(i<0||i>=n||j<0||j>=m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=1;
        
        for(int k=0;k<4;k++){
            int x=i+dx[k], y=j+dy[k];
            
            if(x>=0 && x<n && y>=0 && y<m && mat[i][j]<mat[x][y])
                val=max(val,1+dfs(mat,n,m,x,y,dp));
        }
        
        return dp[i][j]=val;
        
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int maxv=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxv=max(maxv,dfs(mat,n,m,i,j,dp));
            }
        }
        
        return maxv;
    }
};