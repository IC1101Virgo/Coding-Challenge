class Solution {
public:
    void helper(vector<int> &A, int B, vector<vector<int>> &res, vector<int> v){
        if(B<0)
            return;
        
        if(B==0){
            sort(v.begin(),v.end());
            for(auto x:res){
                if(x==v)
                    return;
                }
            res.push_back(v);
        }
        
        for(int i=0;i<A.size();i++){
            if(B-A[i]>=0){
                v.push_back(A[i]);
                helper(A,B-A[i],res,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
      
        vector<vector<int>> res;
        vector<int> v;
        helper(A,B,res,v);
        return res;
    }
};