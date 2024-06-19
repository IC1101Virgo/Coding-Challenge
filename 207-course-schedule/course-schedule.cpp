class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int idx, vector<int> &vis, vector<int> &dfsvis){

        vis[idx]=1;
        dfsvis[idx]=1;

        for(auto ele: adj[idx]){
            if(!vis[ele])
            {
                if(dfs(adj, ele, vis, dfsvis))
                return 1;
            }

            else if(dfsvis[ele]==1)
            return 1;
            
        }

        dfsvis[idx]=0;
        return 0;

    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        

        vector<vector<int>> adj(n);

        for(auto x:pre){
            adj[x[0]].push_back(x[1]);
            //adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(adj, i, vis, dfsvis))
                return 0;
            }
        }

        return 1;
    }
};