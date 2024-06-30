class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) //topological sort
    {
        int n = quiet.size();
        vector<int> ans(n), adj[n], indegree(n,0);
        queue<int> q;
        int v;
        
        for(auto r: richer)
        {
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        for(int i=0; i<n; i++)
        {
            ans[i] = i;
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())   //BFS topo sort
        {
            v = q.front(), q.pop();
            
            for(auto u: adj[v])
            {
                if(quiet[ans[v]] < quiet[ans[u]])  //v is richer than u and b/c ans[v] can also be some other value than v which is more rich and is quietest and quieter than ans[u] then ans[u] will be ans[v]
                    ans[u] = ans[v];
                if(--indegree[u] == 0)
                    q.push(u);
            }
        }
        return ans;
    }
};