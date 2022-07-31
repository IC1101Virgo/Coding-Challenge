class Solution {
public:
    void dfs(vector<vector<int>>& is, int i, vector<int> &vis){
        int n=is.size();
        
        vis[i]=1;
        
        for(int j=0; j<n; j++){
            if(!vis[j] && is[i][j]==1){
                dfs(is, j, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int ans=0;
        
        int n=is.size();
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(is,i,vis);
            }
        }
        
        return ans;
    }
};