class Solution {
public:
    void dfs(vector<int> adj[], int idx, vector<int> &vis){
        if(vis[idx])
        return;

        vis[idx]=1;

        for(auto ele:adj[idx]){
            if(vis[ele]==0)
            dfs(adj, ele, vis);
        }

        return;
    }
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();

        vector<int> adj[n+1];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(is[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int pro =0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                pro++;
            }
        }

        return pro;
    }
};