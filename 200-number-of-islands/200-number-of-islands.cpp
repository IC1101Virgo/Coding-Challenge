class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int dfs(vector<vector<char>>& grid, int i ,int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1')
            return 0;
        
        grid[i][j]='2';
        
        for(int k=0;k<4;k++){
           int x=i+dx[k], y=j+dy[k];
            
             dfs(grid,x,y,n,m);
        }
        
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int maxv=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')
                    if(dfs(grid,i,j,n,m))
                        maxv++;
            }
        }
        
        return maxv;
    }
};