// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    void dfs(vector<vector<int>>& grid, int n, int i, int j, vector<vector<bool>> &vis){
        if(i>=n || i<0 || j>=n || j<0 || vis[i][j]==1 || grid[i][j]==0)
        return;
        
        vis[i][j]=1;
        
        dfs(grid,n,i+1,j,vis);
        dfs(grid,n,i-1,j,vis);
        dfs(grid,n,i,j+1,vis);
        dfs(grid,n,i,j-1,vis);
        
        
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size(), m=grid[0].size();
        int x=-1,y=-1,dx=-1,dy=-1;
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                x=i; y=j;
                }
                else if(grid[i][j]==2){
                dx=i; dy=j;
                }
                
            }
        }
        
        dfs(grid,n,x,y,vis);
        
        return vis[dx][dy];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends