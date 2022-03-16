// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int i, int vis[],int dfsvis[], vector<int> adj[]){
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto edge:adj[i]){
            if(vis[edge]==0)
            {
                if(helper(edge,vis,dfsvis,adj))
                return true;
            }
            
            else if(dfsvis[edge]==1)
            return true;
        }
        
        dfsvis[i]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        int vis[v], dfsvis[v];
        memset(vis,0,sizeof(vis));
        memset(dfsvis,0,sizeof(dfsvis));
        
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                if(helper(i,vis,dfsvis,adj))
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