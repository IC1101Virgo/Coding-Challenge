class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        
        int top=0, down=n-1, left=0, right=m-1;
        vector<int> v;
        
        while(top<=down && left<=right){
            for(int i=left; i<=right; i++){
                v.push_back(mat[top][i]);
            }
            
            top++;
            
            for(int i=top; i<=down; i++){
                v.push_back(mat[i][right]);
            }
            
            right--;
            
            if(top>down || left>right)
                break;
            
            for(int i=right; i>=left; i--){
                v.push_back(mat[down][i]);
            }
            
            down--;
            
            for(int i=down; i>=top; i--){
                v.push_back(mat[i][left]);
            }
            
            left++;
            
        }
        
        return v;
    }
};