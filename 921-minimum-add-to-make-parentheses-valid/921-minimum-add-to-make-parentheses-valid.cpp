class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        
        stack<char> st;
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(s[i]);
            
            else{
                if(st.empty())
                    cnt++;
                
                else if(st.top()=='(')
                    st.pop();
                
                else st.push('(');
            }
        }
        
        return st.size()+cnt;
    }
};