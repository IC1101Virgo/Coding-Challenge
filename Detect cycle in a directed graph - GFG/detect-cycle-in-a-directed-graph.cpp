// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool helper(vector<int> adj[], vector<int> &vis, int id){
        if(vis[id]==1)
        return true;
        
        if(vis[id]==0){
            vis[id]=1;
            
            for(auto edge:adj[id]){
                if(helper(adj,vis,edge))
                return true;
            }
        }
        
        vis[id]=2;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v,0);
        
        for(int i=0;i<v;i++){
            if(helper(adj,vis,i))
            return true;
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