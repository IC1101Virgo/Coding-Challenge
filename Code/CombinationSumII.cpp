void helper(vector<int> &A, int B, vector<int>&curr, set<vector<int>> &s, int index){
    if(B==0)
    {
        s.insert(curr);
        return;
    }
    
    if(index>=A.size())
    return;
    curr.push_back(A[index]);
    helper(A,B-A[index],curr,s,index+1);
    curr.pop_back();
    helper(A,B,curr,s,index+1);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    vector<int>curr;
    set<vector<int>>s;
    helper(A,B,curr,s,0);
    vector<vector<int>>res;
    for(auto it:s)
    res.push_back(it);
    return res;
    
}
