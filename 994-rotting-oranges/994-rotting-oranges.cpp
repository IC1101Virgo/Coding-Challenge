class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();
        
        queue<pair<int,int>> q;
        
        int orange=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                
                if(grid[i][j]==1)
                    orange++;
            }
        }
        
        int time=0;
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        while(!q.empty() && orange){
            int size=q.size();
            
            while(size--){
                auto [x,y]=q.front();
                
                q.pop();
                
                for(int k=0;k<4;k++){
                    int a=x+dx[k];
                    int b=y+dy[k];
                    
                    if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==1){
                        orange--;
                        grid[a][b]=2;
                        q.push({a,b});
                    }
                }
                
            }
            
            time++;
        }
        
        if(orange==0)
            return time;
        
        else return -1;
    }
};