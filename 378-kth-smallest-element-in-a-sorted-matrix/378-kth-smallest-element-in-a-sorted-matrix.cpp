class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
       priority_queue<int> pq;
        
        int n=mat.size(), m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(mat[i][j]);
                
                if(pq.size()>k)
                    pq.pop();
            }
        }
        
        return pq.top();
    }
};