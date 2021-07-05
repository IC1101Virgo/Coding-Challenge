vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,int>mp;
    int n=A.size();
    
    for(int i=0;i<n;i++){
        if(mp.find(A[i])!=mp.end()){
            int index=mp[A[i]];
            A[index]++;
            mp[A[index]]=index;
        }
        mp[A[i]]=i;
    }
    
    return A;
}
