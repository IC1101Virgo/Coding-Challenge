class Solution {
public:
    void helper(vector<int>& can, int t,vector<int> v,int in,int sum, vector<vector<int>> &res){
        if(sum>t)
            return;
        
        if(sum==t){
            res.push_back(v);
            return;
        }
        
        for(int i=in;i<can.size();i++){
            v.push_back(can[i]);
            sum += can[i];
            helper(can, t, v, i, sum, res);
            sum -= can[i];
            v.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<int> v;
        vector<vector<int>> res;
        
        helper(can,t,v,0,0,res);
        
        return res;
    }
};