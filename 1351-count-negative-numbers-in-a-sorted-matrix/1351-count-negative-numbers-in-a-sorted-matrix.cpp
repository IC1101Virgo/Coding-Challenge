class Solution {
public:
    int ans=0;
    void helper(vector<vector<int>>& grid, int i, int hi, int lo){
        
        while(lo<hi){
            int mid=(lo+hi)/2;
            
            if(grid[i][mid]>=0)
                lo=mid+1;
            
            else hi=mid;
        }
        
        if(grid[i][hi]<0)
        ans+=grid[0].size()-hi;
        
        return;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
       // int ans=0;
        
        for(int i=0; i<n; i++){
            helper(grid, i, m-1, 0);
        }
        
        return ans;
    }
};