class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& b){
         if(i<0 || j<0 || i == b.size() || j == b[0].size() || b[i][j] != 'O') {
        return;
    }
    b[i][j] = 'a';
    dfs(i-1, j,b);
    dfs( i+1, j,b);
    dfs( i, j-1,b);
    dfs( i, j+1,b);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(0,i,board);
            
            if(board[n-1][i]=='O')
                dfs(n-1,i,board);
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,board);
            
            if(board[i][m-1]=='O')
                dfs(i,m-1,board);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                
                if(board[i][j]=='a')
                    board[i][j]='O';
            }
        }
        
    }
};
