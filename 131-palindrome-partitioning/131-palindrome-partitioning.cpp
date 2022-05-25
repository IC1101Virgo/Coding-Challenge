class Solution {
public:
    bool palindrome(string str){
        int i=0, j=str.length()-1;
        
        while(i<=j){
            if(str[i]!=str[j])
                return false;
            
            else{
                i++;
                j--;
            }
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