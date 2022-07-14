class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        int n=board.size(), m=board[0].size();
        
        if(i<0 ||i>=n || j<0 || j>=m || board[i][j]!='O')
            return;
        
        board[i][j]='a';
        
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
            
            if(board[i][m-1]=='O')
                dfs(board,i,m-1);
        }
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(board,0,i);
            
            if(board[n-1][i]=='O')
                dfs(board,n-1,i);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                
                if(board[i][j]=='a')
                    board[i][j]='O';
            }
        }
        
        return;
    }
};