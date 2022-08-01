class Solution {
public:
    string simplifyPath(string path) {
        
        int n=path.size();
        
        vector<string> v;
        
        for(int i=0; i<n; i++){
            string res="";
            
            while(i<n && path[i] != '/'){
                res+=path[i];
                i++;
            }
            
            if(res == "" || res == "."){
                continue;
            }
            
            else
            {
            if(res==".."){
                if(v.size()>0)
                    v.pop_back();
            }
                else
            v.push_back(res);
            
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