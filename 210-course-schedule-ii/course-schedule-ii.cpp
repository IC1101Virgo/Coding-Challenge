class Solution {
public:
    bool iscycle(vector<int> &vis, vector<int> &dfsvis, int i, vector<int> adj[],stack<int> &s){
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto edge:adj[i]){
            if(!vis[edge]){
                if(iscycle(vis,dfsvis,edge,adj,s))
                    return true;
            }
            else if(dfsvis[edge]==true)
                return true;
        }
        
        dfsvis[i]=0;
        s.push(i);
        
        return false;
    }
    

    
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> adj [num+1];
        
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> res;
        stack<int> s;
        vector<int> vis(num,0);
        vector<int> dfsvis(num,0);
        
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(iscycle(vis,dfsvis,i,adj,s)){
                    return res;

                }
            }
        }
  
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        return res;
        
        
    }
};