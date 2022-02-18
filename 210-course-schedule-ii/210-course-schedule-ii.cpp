class Solution {
public:
    bool kahn(int n, vector<int> adj[], vector<int> &indegree, vector<int> &ans){
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        int count=0;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            for(auto edge:adj[x]){
                indegree[edge]--;
                
                if(indegree[edge]==0)
                    q.push(edge);
            }
            ans.push_back(x);
            count++;
        }
        
        if(count!=n)
            return false;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int num=pre.size();
        
        vector<int> adj[n];
        vector<int> ans;
        vector<int>indegree(n,0);
        
        for(auto edge:pre){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        
        if(kahn(n,adj,indegree,ans))
            return ans;
        
        else return{};
    }
};