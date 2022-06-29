class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        
        int top=0, down=n-1, right=n-1, left=0;
        int count=1;
        
        while(top<=down && left<=right){
           for(int i=left;i<=right;i++){
               res[top][i]=count;
               count++;
           }
            
            top++;
            
            for(int i=top;i<=down;i++){
                res[i][right]=count;
                count++;
            }
            
            right--;
            
            if(top>down ||right<left)
                break;
            
            for(int i=right;i>=left;i--){
                res[down][i]=count;
                count++;
            }
            down--;
            
            for(int i=down;i>=top;i--){
                res[i][left]=count;
                count++;
            }
            
            left++;
        }
        
        return res;
    }
};