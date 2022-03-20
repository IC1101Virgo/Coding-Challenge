class Solution {
public:
    string simplifyPath(string A) {
        vector<string> v;
    string ans="";
    for(int i=0;i<A.length();i++){
        string path="";
        while(i<A.length() && A[i]!='/')
        path+=A[i++];
        if(path=="" || path==".")
        continue;
        else 
        if(path=="..")
        {
            if(v.size()>0)
            v.pop_back();
        }
        else v.push_back(path);
    }
    if(v.size()==0)
    return "/";
    for(int i=0;i<v.size();i++)
    ans+="/"+v[i];
    return ans;
    }
};