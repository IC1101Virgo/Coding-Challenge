class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> v, int ind, vector<int> &A, int B){
    int n=A.size();
    
    if(B<0)
    return;
    
    if(B==0){
       
        res.push_back(v);
        return;
    }
    
    for(int i=ind;i<n;i++){
        if(i>ind && A[i]==A[i-1])
            continue;
            v.push_back(A[i]);
            helper(res,v,i+1,A,B-A[i]);
            v.pop_back();
        
    }
    
    return;
}
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        sort(A.begin(),A.end());
    vector<vector<int>> res;
    vector<int> v;
    helper(res,v,0,A,B);
   
    return res;
    }
};