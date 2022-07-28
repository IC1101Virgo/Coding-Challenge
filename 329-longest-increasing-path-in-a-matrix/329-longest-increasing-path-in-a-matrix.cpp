class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int dfs(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp){
        int n=mat.size(), m=mat[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=0;
        
        for(int k=0;k<4;k++){
            int a=i+dx[k];
            int b=j+dy[k];
            
            if(a>=0 && a<n && b>=0 && b<m && mat[a][b]>mat[i][j])
            val=max(val,1+dfs(mat,a,b,dp));
        }
        
        return dp[i][j]=val;
        
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
       int n=mat.size(), m=mat[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxv=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxv=max(maxv,1+dfs(mat,i,j,dp));
            }
        }
        
        return maxv;
    }
};