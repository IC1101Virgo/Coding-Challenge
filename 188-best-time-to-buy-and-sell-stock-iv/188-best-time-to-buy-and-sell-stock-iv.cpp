class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        vector<int> sell(k+1,0), buy(k+1,INT_MIN);
        
        for(int i=0;i<n;i++){
            for(int j=k;j>0;j--){
                sell[j]=max(sell[j],buy[j]+prices[i]);
                buy[j]=max(buy[j],sell[j-1]-prices[i]);
            }
        }
        
        return sell[k];
    }
};