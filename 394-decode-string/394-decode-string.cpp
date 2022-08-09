class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        
        stack<pair<string, int>> stk;
        
        int num=0;
        string ans="";
        
        for(int i=0; i<n; i++){
            if(isalpha(s[i]))
                ans+=s[i];
            
        else if(isdigit(s[i]))
            num=num*10+(s[i]-'0');
            
            else if(s[i]=='['){
                stk.push({ans,num});
                ans="";
                num=0;
            }
            
            else if(s[i]==']'){
                string tmp=ans;
                
                for(int i=1; i<stk.top().second; i++){
                    tmp+=ans;
                }
                
                ans=stk.top().first+tmp;
                stk.pop();
            }
        }
        
        return ans;
    }
};