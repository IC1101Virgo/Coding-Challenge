class Solution {
public:
    void bfs(vector<vector<int>>& is, int i, vector<int> &vis){
        int n=is.size();
        
        queue<int> q;
        q.push(i);
        vis[i]=1;
        
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            
            for(int j=0;j<n;j++){
                if(!vis[j] && is[temp][j]==1){
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int ans=0;
        
        int n=is.size();
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                bfs(is,i,vis);
            }
        }
        
        return ans;
    }
};