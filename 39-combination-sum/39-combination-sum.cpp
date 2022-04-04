class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> v,  vector<int> &A, int B){
    int n=A.size();
    
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
    
    for(int i=0;i<n;i++){
        if(B-A[i]>=0){
            v.push_back(A[i]);
            helper(res,v,A,B-A[i]);
            v.pop_back();
        }
    }
    
    return;
}
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        sort(A.begin(),A.end());
    vector<vector<int>> res;
    vector<int> v;
    helper(res,v,A,B);
    sort(res.begin(),res.end());
    return res;
    }
};