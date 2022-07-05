class Solution {
public:
    int longestValidParentheses(string s) {
       int n=s.size();
        
        int res=0;
        
        stack<int>st;
        int maxx=0;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            
            else{
                if(!st.empty()) st.pop();
                
                if(!st.empty()) maxx=max(maxx,i-st.top());
                
                else st.push(i);
                
            }
        }
        
        return maxx;
    }
};