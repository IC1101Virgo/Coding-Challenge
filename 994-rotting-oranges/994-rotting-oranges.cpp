class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int oranges=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    oranges++;
                
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        
        while(!q.empty() && oranges!=0){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                pair<int,int> curr=q.front();
                q.pop();
                for(auto d:dir){
                    int x=curr.first+d[0];
                    int y=curr.second+d[1];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        oranges--;
                    }
                }
                
            }
            time++;
        }
        
        return oranges==0?time:-1;
    }
};