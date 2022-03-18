// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<V;i++){
	        
	        if(col[i]==-1){
	        q.push({i,0});
	        col[i]=0;
	        
	        while(!q.empty()){
	            pair<int,int>p=q.front();
	            q.pop();
	            
	            int v=p.first;
	            int c=p.second;
	            
	            
	            for(auto j:adj[v]){
	                if(col[j]==c)
	                return 0;
	                
	                if(col[j]==-1){
	                    col[j]=c?0:1;
	                    q.push({j,col[j]});
	                }
	            }
	            
	        }
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