class Solution {
public:
    vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res={};
    
    void helper(string digits, vector<string> &res,int in, string s){
        if(in==digits.size()){
            res.push_back(s);
            return;
        }
        
        for(char c:phone[digits[in]-'0']){
            s.push_back(c);
            helper(digits,res,in+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
        return res;
        string s="";
        helper(digits,res,0,s);
        
        return res;
        }
};