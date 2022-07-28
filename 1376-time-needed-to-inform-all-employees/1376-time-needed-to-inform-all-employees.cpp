class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n+1];
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1)
                continue;
            
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        
        q.push({headID,informTime[headID]});
        int ans=0;
        
        while(!q.empty()){
            auto [node,wt]=q.front();
            q.pop();
            
            for(auto x:adj[node]){
                q.push({x,wt+informTime[x]});
                ans=max(ans,wt+informTime[x]);
            }
        }
        
        return ans;
    }
};