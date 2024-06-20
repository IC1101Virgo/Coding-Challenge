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
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<int> par(n, 0);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
        vector<int> adj[n+1];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(is[i][j])
                {
                    uni(par, i, j);
                }
            }
        }


        int ans=0;

        for(int i=0; i<n; i++){
            if(par[i]==i)
            ans++;
        }

        return ans;


    }
};