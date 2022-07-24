class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        int n=s.size();
        stk.push(-1);
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                stk.push(i);
            
            else{
                
                
                if(!stk.empty())
                    stk.pop();
                
                 if(!stk.empty()){
                   // stk.pop();
                    ans=max(ans,i-stk.top());
                 }    
                     else stk.push(i);
                
            }
        }
        
        return ans;
    }
};