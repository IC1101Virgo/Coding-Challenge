// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        
        int dp[1001][1001];
        
       for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            dp[i][j] = INT_MAX;
            
            dp[0][0]=grid[0][0];
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        
        while(!pq.empty()){
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            int i=p.second.first;
            int j=p.second.second;
            
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                
                if(x>=0 && x<n && y>=0 && y<n && (dp[i][j]+grid[x][y]<dp[x][y])){
                    dp[x][y]=dp[i][j]+grid[x][y];
                    pq.push({dp[x][y],{x,y}});
                }
                
            }
        }
        
        return dp[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends