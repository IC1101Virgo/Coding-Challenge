class Solution {
public:
    int maxProfit(vector<int>& p,int fee) {
     int buy=-p[0], sell=0;
        
        for(int i=1;i<p.size();i++){
            sell=max(sell,buy+p[i]-fee);
            buy=max(buy,sell-p[i]);
        }
        
        return sell;
    }
};