class Solution {
public:
    string simplifyPath(string A) {
        vector<string>v;
        int n=A.size();
        
        string res;
        
        for(int i=0;i<n;i++){
            string path="";
            
            while(i<n && A[i]!='/'){
                path+=A[i];
                i++;
            }
            
            if(path=="" || path==".")
                continue;
            
            else
            if(path=="..")
            {
                if(v.size()>0)
                    v.pop_back();
            }
            else
            v.push_back(path);
        }
        
        for(int i=0;i<v.size();i++)
            res+="/"+v[i];
        
        if(res.size()==0) return "/"; 
            return res;
    }
};