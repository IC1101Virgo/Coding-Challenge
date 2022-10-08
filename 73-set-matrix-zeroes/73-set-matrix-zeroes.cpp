class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r, c;
        int n=matrix.size(), m=matrix[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0)
                {
                    r.insert(i), c.insert(j);
                }
            }
        }
        
        for(auto it=r.begin(); it!=r.end(); it++){
            for(int j=0; j<m; j++){
                matrix[*it][j]=0;
            }
        }
        
        for(auto it=c.begin(); it!=c.end(); it++){
            for(int j=0; j<n; j++){
                matrix[j][*it]=0;
            }
        }
        
        return;
    }
};