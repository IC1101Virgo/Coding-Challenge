// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(int x, vector<int> adj[], vector<int> vis){
        if(vis[x]==2)
        return true;
        
        vis[x]=1;
        
        for(int i=0;i<adj[x].size();i++){
            if(vis[adj[x][i]]==1)
            vis[adj[x][i]]=2;
            
            else{
                if(helper(adj[x][i],adj,vis))
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            vis[i]=1;
            
            for(int j=0;j<adj[i].size();j++){
                if(helper(adj[i][j],adj,vis))
                return true;
            }
            
            vis[i]=0;
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