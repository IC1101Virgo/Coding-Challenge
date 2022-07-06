class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size(),m=mat[0].size(), i=0,j=m-1;
        
        int count=0;
        
        while(i<n && j>=0){
            if(mat[i][j]==t)
                return 1;
            
            else if(mat[i][j]>t){
                j--;
            }
            
            else{
               
                i++;
            }
        }
        
        return 0;
    }
};