class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        
        unordered_map<string,vector<string>> m;
        
        for(int i=0;i<n;i++){
            string temp=strs[i];
            
            sort(temp.begin(),temp.end());
            
            m[temp].push_back(strs[i]);
        }
        
        for(auto x:m)
            ans.push_back(x.second);
        
        return ans;
    }
};