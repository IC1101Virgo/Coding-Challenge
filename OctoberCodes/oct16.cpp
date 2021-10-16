class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, secondBuy = INT_MAX, firstProfit = 0, secondProfit = 0, len = prices.size();
        for(int currPrice: prices) {
            firstBuy = min(firstBuy, currPrice);
            firstProfit = max(firstProfit, currPrice - firstBuy);
            secondBuy = min(secondBuy, currPrice - firstProfit);
            secondProfit = max(secondProfit, currPrice - secondBuy);
        }
        return secondProfit;
    }
};
