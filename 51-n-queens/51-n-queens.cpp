class Solution {
public:
    bool isSafe(int r, int c, vector<string>b){
        int i=r, j = c;
        int n= b.size();
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!= r  && b[i][j] == 'Q')return 0;
            i++;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!=r  && b[i][j] == 'Q')return 0;
            i--;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if( j!=c && b[i][j] == 'Q')return 0;
            j++;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if( j!=c && b[i][j] == 'Q')return 0;
            j--;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!= r && j!=c && b[i][j] == 'Q')return 0;
            i++;j++;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!= r && j!=c && b[i][j] == 'Q')return 0;
            i--;j--;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!= r && j!=c && b[i][j] == 'Q')return 0;
            i++;j--;
        }
        i=r,j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(i!= r && j!=c && b[i][j] == 'Q')return 0;
            i--; j++;
        }
        return 1;
    }
    
    void issafe(int n, vector<vector<string>> &res, vector<string> v, int row){
        if(row==n){
            res.push_back(v);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(row,col,v)){
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