class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, int parent, vector<int> &tin, vector<int> &low,vector<int> &vis, vector<int> adj[], int &timer){
        vis[i]=1;
        
        tin[i]=low[i]=timer++;
        
        for(auto x:adj[i]){
            if(x==parent)
                continue;
            
            if(!vis[x]){
                dfs(x,i,tin,low,vis,adj,timer);
                low[i]=min(low[i],low[x]);
                
                if(low[x]>tin[i])
                    ans.push_back({i,x});
            }
            
            else low[i]=min(low[i],tin[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        for(auto x:connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        int timer=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,vis,adj,timer);
            }
        }
        
        return ans;
    }
};