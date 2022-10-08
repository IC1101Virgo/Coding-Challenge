class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>& b, string w, int i, int j, int idx){
        int nn=w.size(), n=b.size(), m=b[0].size();
        
        if(idx==nn)
            return 1;
        
        if(i>=n || i<0 || j>=m || j<0 || b[i][j]!=w[idx])
            return 0;
        
        
        b[i][j]='1';
        
            
    bool check=dfs(b,w,i+1,j,idx+1)||
                dfs(b,w,i-1,j,idx+1)||
                dfs(b,w,i,j+1,idx+1)||
                dfs(b,w,i,j-1,idx+1);
        
        b[i][j]=w[idx];
        
        return check;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size(), m=b[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(w[0]==b[i][j] && dfs(b, w, i, j, 0))
                    return 1;
            }
        }
        
        return 0;
    }
};