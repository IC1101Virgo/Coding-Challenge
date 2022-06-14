// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int> &vis, vector<int> &dfsvis, vector<int> adj[], int id){
        vis[id]=1;
        dfsvis[id]=1;
        
        for(auto edge:adj[id]){
            if(vis[edge]==-1){
                if(dfs(vis,dfsvis,adj,edge))
                return true;
            }
            
            if(dfsvis[edge]==1)
            return true;
        }
        
        dfsvis[id]=-1;
        return false;
    }
	bool isPossible(int A, vector<pair<int, int> >& B) {
	    // Code here
	     vector<int> adj[A];
    
    for(int i=0;i<B.size();i++)
    adj[B[i].first].push_back(B[i].second);
    
    vector<int> vis(A,-1);
        vector<int> dfsvis(A,-1);
        
        for(int i=0;i<A;i++){
            if(vis[i]==-1){
                if(dfs(vis,dfsvis,adj,i))
                return false;
            }
        }
        
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends