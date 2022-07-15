class Solution {
public:
    bool cycle(vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsvis, int i){
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto edge:adj[i]){
            if(!vis[edge]){
                if(cycle(adj,vis,dfsvis,edge))
                    return 1;
            }
            
            else if(dfsvis[edge]==1)
                return 1;
        }
        
        dfsvis[i]=0;
        return 0;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
         vector<vector<int>> adj(num);
        
        for(auto x:pre){
            adj[x[0]].push_back(x[1]);
            //adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(num,0);
        vector<int> dfsvis(num,0);
        
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(cycle(adj,vis,dfsvis,i))
                    return 0;
            }
        }
        
        return 1;
    }
};