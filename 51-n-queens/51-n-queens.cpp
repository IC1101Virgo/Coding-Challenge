class Solution {
public:
    bool issafe(int r,int c, vector<string> v){
        int i=r,j=c;
        int n=v.size();
        
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r && v[i][j]=='Q') return 0;
            i++;
        }
        
         i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r && v[i][j]=='Q') return 0;
            i--;
        }
        
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(j!=c && v[i][j]=='Q') return 0;
            j--;
        }
        
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(j!=c && v[i][j]=='Q') return 0;
            j++;
        }
        
         i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r && j!=c && v[i][j]=='Q') return 0;
            i++; j--;
        }
        
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r && j!=c && v[i][j]=='Q') return 0;
            i++; j++;
        }
        
         i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r && j!=c && v[i][j]=='Q') return 0;
            i--; j++;
        }
        
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r && j!=c && v[i][j]=='Q') return 0;
            i--; j--;
        }
        
        return 1;
    }
    void helper(int n,  vector<vector<string>> &res, vector<string> v, int row){
        if(row==n){
            res.push_back(v);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(issafe(row,col,v)){
                v[row][col]='Q';
                helper(n,res,v,row+1);
                v[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> v(n,string(n,'.'));
        
        helper(n,res,v,0);
        return res;
    }
};