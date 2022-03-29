// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	     int dist[n];
	    memset(dist,INT_MAX,sizeof(dist));
	    dist[0] =0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<edges.size();j++){
	            vector<int> curr_edge = edges[j];
	            int u = curr_edge[0],v=curr_edge[1], wt = curr_edge[2];
	            if(dist[v]> dist[u] + wt){
	                dist[v] = dist[u]+ wt;
	            }
	        }
	    }
	    for(int j=0;j<edges.size();j++){
	            vector<int> curr_edge = edges[j];
	            int u = curr_edge[0],v=curr_edge[1], wt = curr_edge[2];
	            if(dist[v]> dist[u] + wt){
	                return 1;
	            }
	}
	return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends