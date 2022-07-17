class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        int n=path.size();
        int i=0;
        
        for(int i=0;i<n;i++){
            string str="";
            
            while(i<n && path[i]!='/'){
                str+=path[i];
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
                
                else{
                    v.push_back(str);
                }
            }
        }
        
        string res="";
        
        for(int i=0;i<v.size();i++){
            res+='/'+v[i];
        }
        
        if(res.size()==0)
            return "/";
        
        else return res;
    }
};