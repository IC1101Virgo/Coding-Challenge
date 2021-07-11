vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>>pq;
    
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    
    for(int i=0;i<A.size();i++)
    pq.push({A[0]+B[i],{0,i}});
    
    while(ans.size()<A.size()){
        auto p=pq.top();
        pq.pop();
        int sum=p.first;
        auto idx=p.second;
        int i=idx.first;
        int j=idx.second;
        
        ans.push_back(sum);
        
        pq.push({A[i+1]+B[j],{i+1,j}});
    }
    
    return ans;
}
