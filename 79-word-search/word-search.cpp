int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool dfs(vector<vector<char>> &A, string B, int i, int j, int idx){
    int n=A.size(), m=A[0].size();
    
    if(idx==B.size())
    return 1;
    
    if(i>=n||i<0 ||j<0 ||j>=m || A[i][j]!=B[idx])
    return 0;
    
    
    A[i][j] = '1';
    bool check=0;
    
    for(int k=0;k<4;k++){
        int x=i+dx[k],y=j+dy[k];
        
        if(x>=0 && x<n &&y>=0 &&y<m)
       check= dfs(A,B,x,y,idx+1);

       if(check==1)
       return 1;
    }
    
    A[i][j] = B[idx];
    return check;
}
class Solution {
public:
    bool exist(vector<vector<char>>& A, string B) {
        int n=A.size(), m=A[0].size();

        if(B.size()==1 && A[0][0]==B[0])
        return 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(B[0]==A[i][j] && dfs(A,B,i,j,0))
            return 1;
        }
    }
    
    return 0;
    }
};