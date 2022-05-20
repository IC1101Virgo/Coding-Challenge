class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            string ans="";
            
            if(s[i]==' ') continue;
            
            while(s[i]!=' ' && i<n){
                ans+=s[i];
                i++;
            }
            
            st.push(ans);
        }
        
        string res="";
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
            
            if(!st.empty())
            res+=" ";
        }
        
        return res;
    }
};