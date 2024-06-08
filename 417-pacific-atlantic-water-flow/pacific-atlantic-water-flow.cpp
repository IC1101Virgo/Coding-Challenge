class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j){
        int n=h.size(), m=h[0].size();

        if(i>=n || i<0 || j>=m || j<0 )
        return;

        vis[i][j] = 1;

        if(i-1>=0 && i-1<n && vis[i-1][j]!=1 && h[i-1][j]>=h[i][j])
        dfs(h, vis, i-1, j);

        if(i+1>=0 && i+1<n && vis[i+1][j]!=1 && h[i+1][j]>=h[i][j])
        dfs(h, vis, i+1, j);

        if(j-1>=0 && j-1<m && vis[i][j-1]!=1 && h[i][j-1]>=h[i][j])
        dfs(h, vis, i, j-1);

        if(j+1>=0 && j+1<m && vis[i][j+1]!=1 && h[i][j+1]>=h[i][j])
        dfs(h, vis, i, j+1);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(), m=h[0].size();

        vector<vector<bool>> a(n, vector<bool> (m,0));
        vector<vector<bool>> p(n, vector<bool> (m,0));
        vector<vector<int>> res;

        for(int i=0; i<n; i++)
        {
            dfs(h, p, i, 0);
            dfs(h, a, i, m-1);
        }

        for(int i=0; i<m; i++){
            dfs(h, p, 0, i);
            dfs(h, a, n-1, i);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] && p[i][j])
                res.push_back({i,j});
            }
        }

        return res;
        
    }
};