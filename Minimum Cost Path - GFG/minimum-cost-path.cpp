// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	typedef pair<int,pair<int,int>> pi;
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
         int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        dp[0][0]=grid[0][0];
        pq.push({dp[0][0],{0,0}});
        
       
        
        while(!pq.empty()){
            auto prime=pq.top();
            pq.pop();
            
            int a=prime.second.first;
            int b=prime.second.second;
            
            
             for(int i=0;i<4;i++){
                int x=a+dx[i];
                int y=b+dy[i];
                
                if(x>=0 && x<n && y>=0 && y<n && dp[a][b]+grid[x][y]<dp[x][y]){
                    dp[x][y]=dp[a][b]+grid[x][y];
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