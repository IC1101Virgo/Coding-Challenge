class Solution {
public:
    int dx[8]={1,0,-1,0,1,-1,1,-1};
    int dy[8]={0,1,0,-1,1,-1,-1,1};
    
    void helper(vector<vector<int>>& copy, vector<vector<int>>& board, int n, int m, int i, int j, int cnt1){
        if(copy[i][j]==0 && cnt1==3)
            board[i][j]=1;
        
        else if(copy[i][j]==1 && cnt1<2)
            board[i][j]=0;
        
        else if(copy[i][j]==1 && cnt1>3)
            board[i][j]=0;
            
    }
    
    void solve(vector<vector<int>>& copy, vector<vector<int>>& board, int n, int m, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m)
            return;
        
        int cnt1=0;
        
        for(int k=0; k<8; k++){
            int x= i+dx[k];
            int y= j+dy[k];
            
            if(x>=0 && x<n && y>=0 && y<m && copy[x][y]==1)
                cnt1++;
        }
        
        helper(copy, board, n, m, i, j, cnt1);
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy;
        int n=board.size(), m=board[0].size();
        
        copy=board;
        
        //life(copy, board, n, m);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                solve(copy, board, n, m, i, j);
            }
        }
        
        return;
        
    }
};