// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(vector<int>adj[], vector<int> &col, int ind){
        
        queue<int> q;
        q.push(ind);
        col[ind]=1;;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto x:adj[node]){
                
                if(col[x]==-1){
                    col[x]=1-col[node];
                    q.push(x);
                }
                
                else if(col[x]==col[node])
                return 0;
            }
        }
        
        return 1;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    
	    vector<int> col(v,-1);
	    
	    for(int i=0;i<v;i++){
	        if(col[i]==-1){
	            if(!helper(adj,col,i))
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