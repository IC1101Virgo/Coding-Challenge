class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();

        set<int> r, c;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for(int i=0; i<n; i++){
        for(auto ele:r){
            mat[ele][i]=0;
        }
        }

        for(int i=0; i<m; i++){
        for(auto ele:c){
            mat[i][ele]=0;
        }
        }

        return;
    }
};
