class Solution {
public:
    int longestValidParentheses(string str) {
        int n=str.size();
        int ans=0;
        stack<int> s;
        s.push(-1);
        
        for(int i=0;i<n;i++){
            if(str[i]=='(')
                s.push(i);
            
            else{
                if(!s.empty()) s.pop();
                
                if(!s.empty()) ans=max(ans,i-s.top());
                
                else s.push(i);
            }
        }
        
        return ans;
    }
};