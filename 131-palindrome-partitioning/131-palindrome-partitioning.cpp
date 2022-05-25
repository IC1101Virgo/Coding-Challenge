class Solution {
public:
    bool palindrome(string str){
        for(int i=0;i<str.length();i++){
            if(str[i]!=str[str.length()-i-1])
                return 0;
        }
        
        return 1;
    }
    
    void helper(string s, vector<vector<string>> &res, vector<string> temp, int in){
        if(in==s.size()){
            res.push_back(temp);
            return;
        }
        
        string x="";
        for(int i=in;i<s.size();i++){
            x+=s[i];
            if(palindrome(x)){
                
                temp.push_back(x);
                helper(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> temp;
        
        helper(s,res,temp,0);
        
        return res;
    }
};