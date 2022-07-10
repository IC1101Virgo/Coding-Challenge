class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        queue<pair<int,int>>q;
        int orange=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                
                if(grid[i][j]==1)
                    orange++;
            }
        }
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int time=0;
        
        while(!q.empty() && orange!=0){
            int s=q.size();
            
            for(int i=0;i<s;i++){
            auto temp=q.front();
            q.pop();
            
            
            for(int i=0;i<4;i++){
              int x=temp.first+dx[i];
               int y=temp.second+dy[i];
                
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                    grid[x][y]=2;
                    q.push({x,y});
                    orange--;
                }
            }
            }   
            time++;
        }
        
        if(orange==0 )
            return time;
        
        return -1;
    }
};