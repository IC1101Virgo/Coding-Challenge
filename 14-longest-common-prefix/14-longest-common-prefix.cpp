class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=1;
        
        string x=strs[0];
        
        while(i<strs.size()){
            
            for(int j=0; j<x.size(); j++){
                if(x[j]!=strs[i][j])
                {
                    //x=x.substr(0,j);
                    x.erase(j);
                    break;
                }
            }
            
            i++;
        }
        
        return x;
    }
};