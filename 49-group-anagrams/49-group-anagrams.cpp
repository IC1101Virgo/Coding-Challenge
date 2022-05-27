class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        
        int n=strs.size();
        
        for(int i=0;i<n;i++){
            string x=strs[i];
            sort(x.begin(),x.end());
            
            mp[x].push_back(strs[i]);
        }
        
        for(auto ele:mp){
            res.push_back(ele.second);
        }
        
        return res;
        
    }
};