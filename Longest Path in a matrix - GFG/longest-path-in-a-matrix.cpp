// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
      int dx[4] = {-1,1,0,0};
     int dy[4] = {0,0,-1,1};
    int path(vector<vector<int>>& matrix , int n , int m , int x ,int y ,vector<vector<int>>&t){
        if(x < 0 || y <0 || x>=n || y>=m){
            return 0 ;
        }
        if(t[x][y] != -1){
            return t[x][y];
        }
        int val = 1 ;
        for(int i = 0 ; i<4 ; i++){
            int nx = x+ dx[i] ;
            int ny = y + dy[i] ;
            if(nx >= 0 && ny >= 0  && nx < n && ny < m && matrix[nx][ny] > matrix[x][y]){
                val = max(val , 1 + path(matrix , n , m, nx ,ny,t)) ;
            }
        }
        return t[x][y] = val ;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
          int maxv=0;
       // int n=mat.size(), m=mat[0].size();
        int n= matrix.size()  , m= matrix[0].size();
        vector<vector<int>>t(n+1,vector<int>(m+1,-1)) ;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxv=max(maxv,path(matrix,n,m,i,j,t));
            }
        }
        
        return maxv;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends