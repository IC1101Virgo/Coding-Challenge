class Solution {
public:
    bool palindrome(string str, int b, int e){
        while(b<=e){
            if(str[b]!=str[e])
                return 0;
            
            else{
                b++;
                e--;
            }
        }
        
        return 1;
    }
    
    void helper(string s, vector<vector<string>> &res, vector<string> temp, int in){
        if(in==s.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i=in;i<s.size();i++){
            
            if(palindrome(s,in,i)){
                 string x=s.substr(in,i-in+1);
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