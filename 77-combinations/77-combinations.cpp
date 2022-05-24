class Solution {
public:
    vector<vector<int>> res;
    
    void helper(int n, int k, int in, vector<int> v){
        if(v.size()==k){
            res.push_back(v);
            return;
        }
        
        for(int i=in;i<n;i++){
            v.push_back(i+1);
            helper(n,k,i+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        helper(n,k,0,{});
        return res;
    }
};