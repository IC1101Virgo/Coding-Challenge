// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
          if(A[0][0]==0) return -1;
       vector<int> moves={1,0,-1,0,1};
       queue<vector<int>>q;
       q.push({0,0,0});
       A[0][0]=0;
       while(!q.empty()){
           int x=q.front()[0],y=q.front()[1],steps=q.front()[2];
           q.pop();
           for(int i=0;i<4;i++){
               int nx=x+moves[i],ny=y+moves[i+1];
               if(nx>=0 && ny>=0 && nx<N && ny<M && A[nx][ny]==1){
                   if(nx==X && ny==Y){
                       return steps+1;
                   }else{
                       A[nx][ny]=0;
                       q.push({nx,ny,steps+1});
                   }
               }
           }
       }
       return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends