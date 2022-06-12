// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isbipartite(vector<int> &col, vector<int> adj[], int i){
    queue<int> q;
    q.push(i);
    col[i]=1;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(auto id:adj[node]){
            
            if(col[id]==-1){
                col[id]=1-col[node];
                q.push(id);
            }
            
            else if(col[id]==col[node])
            return false;
        }
    }
    
    return true;
}
	bool isBipartite(int A, vector<int>adj[]){
	    // Code here
	    vector<int> col(A,-1);
	    
	    for(int i=0;i<A;i++){
        if(col[i]==-1){
            if(!isbipartite(col,adj,i))
            return 0;
        }
    }
    
    return 1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends