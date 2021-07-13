vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> vp;
    vector<int> ans;
    
    for(int i=0;i<A.size();i++)
    vp.push_back(make_pair(A[i],B[i]));
    
    sort(vp.rbegin(),vp.rend());
    
    for(int i=0;i<vp.size();i++)
    ans.insert(ans.begin()+vp[i].second,vp[i].first);
    
    return ans;
}
