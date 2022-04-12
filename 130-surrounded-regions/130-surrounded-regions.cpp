class Solution {
public:
    void dfs(int i,int j, vector<vector<char>>& b ){
        
          if(i<0 || j<0 || i == b.size() || j == b[0].size() || b[i][j] != 'O') {
        return;
    }
    b[i][j] = 'a';
    dfs(i-1, j,b);
    dfs( i+1, j,b);
    dfs( i, j-1,b);
    dfs( i, j+1,b);
    }
    void solve(vector<vector<char>>& b) {
        int n=b.size(), m=b[0].size();
        
        for(int i=0;i<m;i++){
            if(b[0][i]=='O')
                dfs(0,i,b);
            
            if(b[n-1][i]=='O')
                dfs(n-1,i,b);
        }
        
        for(int i=0;i<n;i++){
            if(b[i][0]=='O')
                dfs(i,0,b);
            
            if(b[i][m-1]=='O')
                dfs(i,m-1,b);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(b[i][j]=='O')
                    b[i][j]='X';
                
                 if(b[i][j]=='a')
                    b[i][j]='O';
                
            }
        }
    }
};