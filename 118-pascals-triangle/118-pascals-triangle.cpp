class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>> v(nums,vector<int>(nums,1));
        
        for(int i=0;i<nums;i++){
            v[i].resize(i+1);
           
            for(int j=1;j<i;j++)
                v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
        
        
        return v;
        
    }
};