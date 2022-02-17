// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool doDFS(int V, vector<int> adj[], vector<bool> &visited, int i, int par){
        visited[i] = true;
        for(int j = 0; j < adj[i].size(); j++){
            if(visited[adj[i][j]] == false){
                if(doDFS(V, adj, visited, adj[i][j], i)){
                    return true;
                }
            }
            else{
                if(adj[i][j] != par ){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited (V, false);
        bool isCycle = false;
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                isCycle = doDFS(V, adj, visited, i, -1);
            }
            if(isCycle){
                return true;
            }
        }
        return isCycle;
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