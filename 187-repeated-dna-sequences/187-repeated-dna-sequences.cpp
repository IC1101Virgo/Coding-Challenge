class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        
        int n=s.size();
        unordered_map<string, int> mp;
        
        for(int i=0;i<n;i++){
            string str="";
            
                if(i+10<=n){
                str=s.substr(i,10);
                    mp[str]++;
                }
            
            
        }
        
        for(auto x:mp){
            if(x.second>1)
                res.push_back(x.first);
        }
        
        return res;
    }
};