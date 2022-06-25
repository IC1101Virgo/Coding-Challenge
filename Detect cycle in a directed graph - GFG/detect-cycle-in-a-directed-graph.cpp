// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &dfsvis, int i){
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto edge:adj[i]){
            if(!vis[edge]){
                if(dfs(adj,vis,dfsvis,edge))
                return true;
            }
            
            else{
            if(dfsvis[edge]==1)
            return true;
            }
        }
        
        dfsvis[i]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v,0);
        vector<int> dfsvis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(adj,vis,dfsvis,i))
                return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends