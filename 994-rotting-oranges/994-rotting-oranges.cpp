class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
      
        int org=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    org++;
                
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int time=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        while(!q.empty() && org!=0){
            int size=q.size();
            
            while(size--){
                auto temp=q.front();
                
                q.pop();
                
                for(int k=0;k<4;k++){
                    int x=temp.first+dx[k];
                    int y=temp.second+dy[k];
                    
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        grid[x][y]=2;
                        org--;
                        q.push({x,y});
                        }
                }
            }
            
            time++;
        }
        
        if(org==0)
            return time;
        
        else return -1;
    }
};