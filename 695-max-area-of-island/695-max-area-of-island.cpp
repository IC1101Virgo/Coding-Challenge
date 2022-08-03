class Solution {
public:
     int dx[4]={1,0,-1,0};
     int dy[4]={0,1,0,-1};
    
    
    int area(vector<vector<int>>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
        int ans=1;
        
        for(int k=0; k<4; k++){
            
            int x=i+dx[k];
            int y=j+dy[k];
            
            ans+=area(grid, x, y);
        }
        
        return ans;
    }
    
 
   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        

        int ans=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)
                    ans=max(ans,area(grid, i,j));
            }
        }
        
        return ans;
        
    }
};