class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& A) {
          if(A[0][0]==1) return -1;
        int N=A.size(), M=A[0].size();
        
        
       vector<int> dx={1,0,-1,0,1,-1,1,-1};
        vector<int> dy={0,1,0,-1,1,-1,-1,1};
        
        if(N==1 && M==1 && A[0][0]==0)
            return 1;
        
       queue<vector<int>>q;
       q.push({0,0,1});
       A[0][0]=1;
        
       while(!q.empty()){
           int x=q.front()[0],y=q.front()[1],steps=q.front()[2];
           q.pop();
           
           for(int i=0;i<8;i++){
               int nx=x+dx[i],ny=y+dy[i];
               
               if(nx>=0 && ny>=0 && nx<N && ny<M && A[nx][ny]==0){
                   if(nx==N-1 && ny==M-1){
                       return steps+1;
                   }
                   else{
                       A[nx][ny]=1;
                       q.push({nx,ny,steps+1});
                   }
               }
           }
       }
       return -1;
    }
};