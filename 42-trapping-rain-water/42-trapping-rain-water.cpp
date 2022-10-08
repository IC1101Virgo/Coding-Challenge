class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        
        if(n<=2)
            return 0;
        
        int i=0, j=n-1;
        
        int lm=h[i],rm=h[j];
        int ans=0;
        
        while(i<j){
            if(h[i]<h[j]){
                lm=max(h[i],lm);
                    ans+=lm-h[i];
                i++;
            }
            
            else{
                rm=max(h[j],rm);
                    ans+=rm-h[j];
                j--;
            }
        }
        
        return ans;
    }
};