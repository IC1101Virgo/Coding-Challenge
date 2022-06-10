class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<bool>>at,pa;
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>> &mat,int i, int j, vector<vector<int>> &ans){
        int n=h.size(), m=h[0].size();
        
        if(mat[i][j])
            return;
        mat[i][j]=1;
        
        if(at[i][j]==1 && pa[i][j]==1)
            ans.push_back({i,j});
        
        if(i+1<n && h[i+1][j]>=h[i][j]) dfs(h,mat,i+1,j,ans);
        if(i-1>=0 && h[i-1][j]>=h[i][j]) dfs(h,mat,i-1,j,ans);
        if(j+1<m && h[i][j+1]>=h[i][j]) dfs(h,mat,i,j+1,ans);
        if(j-1>=0 && h[i][j-1]>=h[i][j]) dfs(h,mat,i,j-1,ans);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(), m=h[0].size();
        
        if(!n)
            return ans;
        
        at=pa=vector<vector<bool>> (n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            dfs(h,pa,i,0,ans);
            dfs(h,at,i,m-1,ans);
        }
        
        for(int i=0;i<m;i++){
            dfs(h,pa,0,i,ans);
            dfs(h,at,n-1,i,ans);
        }
        
        return ans;
    }
};