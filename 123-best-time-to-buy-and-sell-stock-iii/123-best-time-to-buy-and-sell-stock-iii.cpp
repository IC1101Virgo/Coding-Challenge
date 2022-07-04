class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstbuy=INT_MAX, secondbuy=INT_MAX, fp=0,sp=0;
        
        for(auto cp:prices){
            firstbuy=min(firstbuy,cp);
            fp=max(fp,cp-firstbuy);
            secondbuy=min(secondbuy, cp-fp);
            sp=max(sp,cp-secondbuy);
        }
        
        return sp;
    }
};