class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        
        if(n<=2)
            return 0;
        
        vector<int> l(n),r(n);
        int lm, rm;
        
        lm=h[0];
        
        for(int i=0;i<n;i++){
            lm=max(lm,h[i]);
            l[i]=lm;
        }
        
        rm=h[n-1];
        
        for(int i=n-1;i>=0;i--){
            rm=max(rm,h[i]);
            r[i]=rm;
        }
        
        int water=0;
        
        for(int i=1;i<n-1;i++){
            if(h[i]<l[i] && h[i]<r[i]){
                water+=min(l[i],r[i])-h[i];
            }
        }
        
        return water;
    }
};