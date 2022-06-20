class Solution {
public:
    bool isValid(string str) {
        stack<int> s;
        
        int n=str.size();
        
        for(int i=0;i<n;i++){
            if(str[i]==')'){
                if(!s.empty() && s.top()=='(')
                    s.pop();
                else return false;
            }
            
            else if(str[i]=='}'){
                if(!s.empty() && s.top()=='{')
                    s.pop();
                else return false;
            }
            
            else if(str[i]==']'){
                if(!s.empty() && s.top()=='[')
                    s.pop();
                
                else return false;
            }
            
            else s.push(str[i]);
        }
        
        return s.empty()?1:0;
    }
};