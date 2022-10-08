class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        
        vector<int> l(n), r(n);
        
        int lm=h[0];
       
        
        for(int i=0;i<n;i++){
            l[i]=lm;
            lm=max(lm,h[i]);
        }
        
        int rm=h[n-1];
       
        
        for(int i=n-1;i>=0;i--){
            r[i]=rm;
            rm=max(rm,h[i]);
        }
        
        int water=0;
        
        for(int i=1;i<n-1;i++){
            if(h[i]<l[i] && h[i]<r[i])
                water+=min(l[i],r[i])-h[i];
        }
        
        return water;
    }
};