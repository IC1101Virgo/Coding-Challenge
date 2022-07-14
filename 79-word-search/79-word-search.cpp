class Solution {
public:
    bool dfs(vector<vector<char>> &A, string B, int i, int j, int idx){
    int n=A.size(), m=A[0].size();
    
    if(idx==B.size())
    return 1;
    
    if(i<0 || i>=n || j<0 || j>=m || A[i][j]!=B[idx])
    return 0;
    
        A[i][j]='1';
        
    bool check=dfs(A,B,i+1,j,idx+1)||
                dfs(A,B,i-1,j,idx+1)||
                dfs(A,B,i,j+1,idx+1)||
                dfs(A,B,i,j-1,idx+1);
        
        A[i][j]=B[idx];
                
    return check;
                
}
    bool exist(vector<vector<char>>& A, string B) {
        int n=A.size(), m=A[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(B[0]==A[i][j] && dfs(A,B,i,j,0))
            return 1;
        }
    }
    
    return 0;
    }
};