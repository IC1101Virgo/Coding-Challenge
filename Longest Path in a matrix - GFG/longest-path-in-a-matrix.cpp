// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int path(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& v){
        int n=mat.size(),m=mat[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m)
        return 0;
        
        if(v[i][j]!=-1)
        return v[i][j];
        
        int val=1;
        
        for(int k=0;k<4;k++){
            int x=i+dx[k], y=j+dy[k];
            if(x<n && x>=0 && y<m && y>=0 && mat[i][j]<mat[x][y]){
                val=max(val,1+path(mat,x,y,v));
            }
        }
        
        return v[i][j]=val;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size(), m=mat[0].size();
        
        int maxv=0;
        
        vector<vector<int>> v(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxv=max(maxv,path(mat,i,j,v));
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