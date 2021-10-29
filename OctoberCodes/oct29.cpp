class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int orange=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    orange++;
                
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        
        while(!q.empty() && orange>0){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                q.pop();
                
                for(auto d:dir){
                    int x=p.first+d[0];
                    int y=p.second+d[1];
                    
                    if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    orange--;
                    }
                }
            }
            time++;
        }
        
        return orange==0?time:-1;
    }
};
