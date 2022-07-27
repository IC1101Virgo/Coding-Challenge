class Solution {
public:
    int subArray(vector<int>&a, int k){
        unordered_map<int,int>m;
        int ans = 0;
        int s = 0;
        for(auto i: a){
            s += i;
            if(s == k)ans++;
            if(m.find(s-k) != m.end())ans += m[s-k];
            m[s]++;
        }
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int n=mat.size(), m=mat[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int>arr(m,0);
            for(int j=i;j>=0;j--){
                for(int k=0; k<m; k++){
                    arr[k] += mat[j][k];
                }
                ans += subArray(arr, t);
            }
        }
        
        return ans;
    }
};