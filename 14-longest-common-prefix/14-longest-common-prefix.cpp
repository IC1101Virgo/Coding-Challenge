class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        
        string x=strs[0];
        
        for(int i=1;i<strs.size();i++){
            int len=0;
            string temp="";
            for(int j=0;j<x.size();j++){
                if(strs[i][j]!=x[j]){
                    x=x.substr(0,j);
                    break;
                }
                
                
            }
        }
        
        return x;
    }
};