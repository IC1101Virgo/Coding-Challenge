class Solution {
public:
    void solve(string s, set<string> &di, string curr, vector<string> &res, int in){
        int n=s.size();
        
        if(in==n){
            curr.pop_back();
            res.push_back(curr);
        }
        
        string x="";
        
        for(int i=in;i<n;i++){
            x.push_back(s[i]);
            
            if(di.find(x)!=di.end()){
               // curr.push_back(x);
                //curr+=" ";
                
                solve(s,di,curr+x+" ",res,i+1);
                //curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        
        set<string> di;
        
        for(auto x:wordDict)
            di.insert(x);
        
        vector<string> res;
        
        solve(s,di,"",res,0);
        
        return res;
    }
};