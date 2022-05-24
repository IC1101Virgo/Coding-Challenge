class Solution {
public:
    
    void helper(vector<int> &can, int t, vector<int> v, vector<vector<int>> & res, int ind){
        if(t<0)
            return;
        
        if(t==0)
        {
            res.push_back(v);
            return;
        }
        
        for(int i=ind;i<can.size();i++){
            if(i>ind && can[i]==can[i-1])
                continue;
                v.push_back(can[i]);
                helper(can,t-can[i],v,res,i+1);
                v.pop_back();
            
        }
        
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        sort(can.begin(),can.end());
        vector<vector<int>> res;
        vector<int> v;
        
        helper(can,t,v,res,0);
        
        return res;
    }
};