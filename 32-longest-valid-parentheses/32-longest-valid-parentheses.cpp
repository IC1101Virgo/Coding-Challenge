class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int res=0;
        stack<int>stck;
        stck.push(-1);
        
        for(int i=0;i<n;i++){
          if(s[i]=='(') stck.push(i);
            
            else{
                if(!stck.empty())stck.pop();
                
                if(!stck.empty()){
                    res=max(res,i-stck.top());
                }
                else stck.push(i);
            }
        }
        
        return res;
    }
};