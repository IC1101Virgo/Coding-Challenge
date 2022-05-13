class Solution {
public:
    string helper(string s){
        string res="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt++;
            
            if(s[i]!=s[i+1]){
                res+=to_string(cnt)+s[i];
                cnt=0;
            }
        }
        
        return res;
    }
    string countAndSay(int n) {
        string res="1";
        
        while(--n){
            res=helper(res);
        }
        
        return res;
    }
};