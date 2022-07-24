class Solution {
public:
    void helper(int n, int o, int c, string temp, vector<string> &res){
        if(o>n || c>n || c>o)
            return;
        
        if(o==n && c==n){
            res.push_back(temp);
          //  temp.clear();
          //  return;
        }
        
         helper(n,o+1,c,temp+'(',res);
         helper(n,o,c+1,temp+')',res);
        temp.pop_back();
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,0,0,"",res);
        
        return res;
    }
};