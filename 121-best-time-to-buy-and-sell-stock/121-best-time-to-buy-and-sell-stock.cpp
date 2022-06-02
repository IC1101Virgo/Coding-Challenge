class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int miv=prices[0],maxv=INT_MIN;
        
        for(int i=0;i<n;i++){
            miv=min(miv,prices[i]);
            maxv=max(maxv,prices[i]-miv);
        }
        
        return maxv;
    }
};