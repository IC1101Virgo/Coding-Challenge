class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         if(m*n != original.size())
            return {};
        
        vector<vector<int>> res;
        for(int i=0;i<m*n;){
            vector<int>temp;
            
            for(int j=0;j<n;j++) 
                temp.push_back(original[i++]);
            res.push_back(temp);
        }
        
        return res;
    }
};