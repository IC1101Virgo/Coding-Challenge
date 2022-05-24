class Solution {
public:
    void helper(vector<int> &can, int t, vector<int> v, vector<vector<int>> & res, int ind){
        if(ind==can.size()||t<0)
            return;
        
        if(t==0)
        {
            res.push_back(v);
            return;
        }
        
       v.push_back(can[ind]);
        helper(can,t-can[ind],v,res,ind);
        v.pop_back();
        helper(can,t,v,res,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
      
        sort(can.begin(),can.end());
        vector<vector<int>> res;
        vector<int> v;
        
        helper(can,t,v,res,0);
        
        return res;
    }
};