class Solution {
public:
   bool dfs(vector<int> &vis, vector<int> &dfsvis, vector<int> adj[], int id){
        vis[id]=1;
        dfsvis[id]=1;
        
        for(auto edge:adj[id]){
            if(vis[edge]==-1){
                if(dfs(vis,dfsvis,adj,edge))
                return true;
            }
            
            if(dfsvis[edge]==1)
            return true;
        }
        
        dfsvis[id]=-1;
        return false;
    }
    
    bool canFinish(int v, vector<vector<int>>& p) {
       vector<int> adj[v];
        
        for(auto x:p){
            adj[x[0]].push_back(x[1]);
        }
       vector<int> vis(v,-1);
        vector<int> dfsvis(v,-1);
        
        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(dfs(vis,dfsvis,adj,i))
                return false;
            }
        }
        
        return true;
    }
};