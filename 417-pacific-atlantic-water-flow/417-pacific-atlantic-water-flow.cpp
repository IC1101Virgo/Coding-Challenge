class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<bool>> at,pa;
    
    void dfs(vector<vector<int>>& h,vector<vector<bool>> &mat, int i, int j){
        int n=h.size(), m=h[0].size();
        
        if(mat[i][j]) return;
        mat[i][j]=true;
        
        if(at[i][j]==true && pa[i][j]==true)
            ans.push_back(vector<int>{i,j});
        
        if(i+1<n && h[i+1][j]>=h[i][j]) dfs(h,mat,i+1,j);
        if(i-1>=0 && h[i-1][j]>=h[i][j]) dfs(h,mat,i-1,j);
        if(j+1<m && h[i][j+1]>=h[i][j]) dfs(h,mat,i,j+1);
        if(j-1>=0 && h[i][j-1]>=h[i][j]) dfs(h,mat,i,j-1);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        if(!h.size())
            return ans;
        
        int n=h.size(), m=h[0].size();
       
        at=pa= vector<vector<bool>> (n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            dfs(h,pa,i,0);
            dfs(h,at,i,m-1);
        }
        
         for(int i=0;i<m;i++){
            dfs(h,pa,0,i);
            dfs(h,at,n-1,i);
        }
        
        return ans;
    }
};