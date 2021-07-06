vector<int> Solution::equal(vector<int> &A) {
    vector<vector<int>> ans;
    int n=A.size();
    int i,j;
    unordered_map<int,pair<int,int>>mp;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(mp.find(A[i]+A[j])==mp.end())
            mp[A[i]+A[j]]={i,j};
            
            else{
                int x=mp[A[i]+A[j]].first;
                int y=mp[A[i]+A[j]].second;
                if(x!=i && y!=i && x!=j && y!=j){
                    vector<int> v;
                    v.push_back(x);
                    v.push_back(y);
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans[0];
}
