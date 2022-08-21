class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        int minv=INT_MAX, maxp=0;
        
        for(int i=0;i<n;i++){
            minv=min(minv,p[i]);
            maxp=max(maxp, p[i]-minv);
        }
        
        return maxp;
    }
};