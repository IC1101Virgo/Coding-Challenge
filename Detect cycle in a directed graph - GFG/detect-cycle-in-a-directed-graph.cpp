// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(vector<int> adj[], vector<int> &vis, vector<int> &dfsvis, int idx){
        vis[idx]=1;
        dfsvis[idx]=1;
        
        for(auto x:adj[idx]){
            if(!vis[x]){
                if(helper(adj,vis,dfsvis,x))
                return 1;
            }
            
            else if(dfsvis[x]==1)
            return 1;
        }
        
        dfsvis[idx]=0;
        return 0;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v,0);
        vector<int>dfsvis(v,0);
        
        for(int i=0;i<v;i++)
        {
            if(helper(adj,vis,dfsvis,i))
            return 1;
        }
        
        return 0;
        
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