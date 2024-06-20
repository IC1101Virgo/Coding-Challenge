class Solution {
public:
    int findpar(int node, vector<int> &par){
       if(par[node] != node){
        return findpar(par[node], par);
       }

       return par[node];
        
    }
    
    void uni(vector<int> &par, int a, int b){
        a=findpar(a,par);
        b=findpar(b,par);
        
       if(a==b)
           return;
        
        else{
            par[a]=b;
            return;
        }
        
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2,0);
        int n=edges.size();
        
        vector<int>par (n+1,0);
        
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        
        vector<int> rank(n+1,0);
        
        for(int i=0;i<n;i++){
            
            if(findpar(edges[i][0],par)==findpar(edges[i][1],par))
            {
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
                break;
                
            }
            
            else
            uni(par,edges[i][0],edges[i][1]);
        }
        
        return ans;
        
    }
};