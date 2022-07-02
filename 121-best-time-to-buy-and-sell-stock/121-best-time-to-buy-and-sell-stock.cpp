class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        int minv=p[0], maxp=0;
        
        for(int i=1;i<n;i++){
            minv=min(minv,p[i]);
            maxp=max(maxp,p[i]-minv);
        }
        
        return maxp;
    }
};