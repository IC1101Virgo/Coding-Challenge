class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        
        vector<int> adj[n];
        vector<int> indegree(n,0);
        vector<int> ans;
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]<=1)
            {
                q.push(i);
                indegree[i]--;
            }
        }
        
        while(!q.empty()){
            int s=q.size();
            ans.clear();
            
            for(int i=0;i<s;i++){
                int x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto id:adj[x]){
                    indegree[id]--;
                    if(indegree[id]==1)
                        q.push(id);
                }
            }
        }
        
        return ans;
    }
};