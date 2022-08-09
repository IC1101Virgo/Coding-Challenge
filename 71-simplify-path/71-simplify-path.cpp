class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        
        stack<string> s;
        
        for(int i=0; i<n; i++){
            string res="";
            
            while(i<n && path[i]!='/'){
                res+=path[i];
                i++;
            }
            
            if(res=="." || res=="")
                continue;
            
            else
            {
            if(res==".."){
                if(!s.empty()){
                    s.pop();
                }
            }  
                else{
                    s.push(res);
                }
            
            }
        }
        
        string ans="";
        
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        
        if(ans.size()==0) return "/";
        
        else return ans;
    }
};