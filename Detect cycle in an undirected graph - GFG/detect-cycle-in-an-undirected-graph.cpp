// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(vector<int> adj[], vector<int> &vis, int idx, int par){
        vis[idx]=1;
        
        for(auto x:adj[idx]){
            if(!vis[x]){
                if(helper(adj,vis,x,idx))
                return 1;
            }
            
           else if(par!=x)
            return 1;
        }
        
        return 0;
        
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(v,0);
        
        for(int i=0;i<v;i++){
           if(!vis[i]){
           if(helper(adj,vis,i,-1))
           return 1;
           }
        }
        
        return 0;
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