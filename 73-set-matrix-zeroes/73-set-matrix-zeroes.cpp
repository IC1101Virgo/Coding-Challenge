class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>r,c;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    r.insert(i), c.insert(j);
                }
            }
        }
        
        for(auto i=r.begin(); i!=r.end();i++){
            for(int j=0;j<m;j++){
                matrix[*i][j]=0;
            }
        }
        
        for(auto i=c.begin(); i!=c.end();i++){
            for(int j=0;j<n;j++){
                matrix[j][*i]=0;
            }
        }
    }
};