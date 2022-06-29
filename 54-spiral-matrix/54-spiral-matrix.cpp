class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> v;
        
        int n=ma.size(), m=ma[0].size();
        
        int top=0, down=n-1, left=0, right=m-1;
        
        while(top<=down && left<=right){
            for(int i=left;i<=right;i++){
                v.push_back(ma[top][i]);
            }
            
            top++;
            
            for(int i=top;i<=down;i++){
                v.push_back(ma[i][right]);
            }
            
            right--;
            
            if(top>down || left>right)
                break;
            
            for(int i=right;i>=left;i--){
                v.push_back(ma[down][i]);
            }
            down--;
            
            for(int i=down;i>=top;i--)
                v.push_back(ma[i][left]);
            
            left++;
        }
        
        return v;
    }
};