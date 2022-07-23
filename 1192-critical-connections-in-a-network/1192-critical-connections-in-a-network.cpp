class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis, int &timer, vector<int> adj[]){
        vis[node]=1;
        
        tin[node]=low[node]=timer++;
        
        for(auto x:adj[node]){
            if(x==parent)
                continue;
            
            if(!vis[x]){
                dfs(x,node,tin,low,vis,timer,adj);
                low[node]=min(low[node],low[x]);
                
                if(low[x]>tin[node])
                    ans.push_back({node,x});
            }
            
            else low[node]=min(low[node],tin[x]);
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int>tin(n,-1);
        vector<int>low(n,-1);
        vector<int> vis(n,0);
        
        int timer=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,vis,timer,adj);
            }
        }
        
        return ans;
    }
};