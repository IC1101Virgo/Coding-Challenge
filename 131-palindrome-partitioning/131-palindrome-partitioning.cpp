class Solution {
public:
    bool ispal(string str){
        int i=0, j=str.size()-1;
        
        while(i<=j){
            if(str[i]!=str[j])
                return 0;
            
            else{
                i++;
                j--;
            }
        }
        
        return 1;
    }
    void solve(string s, vector<string> temp, vector<vector<string>> &res, int in){
        int n=s.size();
        
        if(in==n){
            res.push_back(temp);
            return;
        }
        
        string x="";
        
        for(int i=in;i<n;i++){
            
            x+=s[i];
            
            if(ispal(x)){
                temp.push_back(x);
                solve(s,temp,res,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       // int n=s.size();
        
        vector<string> temp;
        vector<vector<string>> res;
        //string x="";
        
        solve(s,temp,res,0);
        
        return res;
    }
};