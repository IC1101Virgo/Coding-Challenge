// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int v, vector<int> adj[], vector<bool> vis, int i, int par){
        vis[i]=1;
        
        for(int j=0;j<adj[i].size();j++){
            if(vis[adj[i][j]]==0){
                if(dfs(v,adj,vis,adj[i][j],i))
                return true;
            }
            
            else{
            if(adj[i][j]!=par)
            return true;
            }
        }
        
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool> vis(v,0);
        
        bool isCycle=0;
        
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                isCycle=dfs(v,adj,vis,i,-1);
            }
            
            if(isCycle)
            return true;
        }
        
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends