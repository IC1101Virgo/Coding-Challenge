class Solution {
public:
    bool helper(vector<string> v, int n, int row,int col){
        if(row==0)
            return true;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='Q'){
                if(col==j|| abs(row-i)==1 && abs(col-j)==1|| abs(row-i)==abs(col-j))
                    return false;
                }
            }
        }
        return true;
    }
    void issafe(int n, vector<vector<string>> &res, vector<string> v, int row){
        if(row==n){
            res.push_back(v);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(helper(v,n,row,col)){
                v[row][col]='Q';
                issafe(n,res,v,row+1);
                v[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> v(n,string(n,'.'));
        
        issafe(n,res,v,0);
        
        return res;
    }
};