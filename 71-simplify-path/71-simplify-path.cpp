class Solution {
public:
    string simplifyPath(string s) {
        int n=s.size();
        
        vector<string> v;
        
        for(int i=0;i<n;i++){
            string str="";
            
            while(i<n && s[i]!='/'){
                str+=s[i];
                i++;
            }
            
            if(str=="" || str==".")
                continue;
            
            else{
                if(str=="..")
                {
                    if(v.size()>0)
                        v.pop_back();
                }
                
                else v.push_back(str);
            }
        }
        
        string res="";
        
        for(int i=0;i<v.size();i++){
            res+='/'+v[i];
        }
        
        if(res.size()==0) return "/"; 
            return res;
    }
};