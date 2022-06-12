// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> &vis, vector<int> adj[], int i, int par){
        vis[i]=1;
        
        for(auto edge:adj[i]){
            if(vis[edge]==-1){
                if(dfs(vis,adj,edge,i))
                return true;
            }
            
            else{
            if(edge!=par)
            return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,-1);
        
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(dfs(vis,adj,i,-1))
                return true;
            }
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