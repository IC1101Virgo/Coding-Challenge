class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
               ans.push_back({node,it});
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n]; 
	for(auto x:connections) {
	    adj[x[0]].push_back(x[1]);
	    adj[x[1]].push_back(x[0]); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
        
        return ans;
    }
};