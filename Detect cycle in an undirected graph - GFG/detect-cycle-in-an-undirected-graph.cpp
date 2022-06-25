// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], vector<int> vis, int i, int par){
        vis[i]=1;
        
        for(auto edge:adj[i]){
            if(vis[edge]==0){
                if(dfs(adj,vis,edge,i))
                return true;
            }
            
            else{
            if(edge!=par)
            return true;
            }
        }
        
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        bool x=0;
        
        for(int i=0;i<v;i++){
            if(vis[i]==0){
           x= dfs(adj,vis,i,-1);
            }
            
            if(x==1)
            return 1;
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