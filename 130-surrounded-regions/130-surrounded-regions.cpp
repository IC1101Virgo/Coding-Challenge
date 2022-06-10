class Solution {
public:
    void dfs(vector<vector<char>>& b, int i,int j){
        int n=b.size(), m=b[0].size();
        
        if(i==n || j==m ||i<0 ||j<0|| b[i][j]!='O')
            return;
        
        b[i][j]='a';
        
        dfs(b,i+1,j);
        dfs(b,i-1,j);
        dfs(b,i,j+1);
        dfs(b,i,j-1);
    }
    void solve(vector<vector<char>>& b) {
        int n=b.size(), m=b[0].size();
        
        for(int i=0;i<n;i++){
            if(b[i][0]=='O')
                dfs(b,i,0);
            
            if(b[i][m-1]=='O')
                dfs(b,i,m-1);
        }
        
        for(int i=0;i<m;i++){
            if(b[0][i]=='O')
                dfs(b,0,i);
            
            if(b[n-1][i]=='O')
                dfs(b,n-1,i);
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