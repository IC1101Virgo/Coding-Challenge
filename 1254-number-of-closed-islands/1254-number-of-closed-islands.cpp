class Solution {
public:
    int dx[4]= {1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j])
            return;
        
        grid[i][j]=1;
        
        for(int k=0; k<4; k++){
            int x=i+dx[k];
            int y=j+dy[k];
            
            dfs(grid, x, y);
        }
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size(), m=grid[0].size();
        
        for(int i=0; i<m; i++){
            dfs(grid, 0, i);
            dfs(grid, n-1, i);
        }
        
        for(int i=0; i<n; i++){
            dfs(grid, i, 0);
            dfs(grid, i, m-1);
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j]==0){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};