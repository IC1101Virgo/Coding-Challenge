// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(vector<vector<char>>& grid, int x, int y){
        int n=grid.size(), m=grid[0].size();
        
        if(x<0 || x>=n|| y<0 || y>=m || grid[x][y]!='1')
        return;
        
        
        grid[x][y]=2;
        
        dfs(grid,x+1,y);
        dfs(grid,x,y+1);
        dfs(grid,x+1,y+1);
        dfs(grid,x-1,y-1);
        dfs(grid,x-1,y);
        dfs(grid,x,y-1);
        dfs(grid,x+1,y-1);
        dfs(grid,x-1,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
       
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                     count++;
                }
            
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends