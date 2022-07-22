class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        
        int buy=-p[0], sell=0;
        if(n<2)
            return 0;
        
        for(int i=1;i<n;i++){
            sell=max(sell,buy+p[i]-fee);
            buy=max(buy,sell-p[i]);
        }
        
        return sell<0?0:sell;
    }
};