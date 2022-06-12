// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> &vis, vector<int> &dfsvis, vector<int> adj[], int id, int par){
        vis[id]=1;
        dfsvis[id]=1;
        
        for(auto edge:adj[id]){
            if(vis[edge]==-1){
                if(dfs(vis,dfsvis,adj,edge,id))
                return true;
            }
            
            if(dfsvis[edge]==1)
            return true;
        }
        
        dfsvis[id]=-1;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v,-1);
        vector<int> dfsvis(v,-1);
        
        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(dfs(vis,dfsvis,adj,i,-1))
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