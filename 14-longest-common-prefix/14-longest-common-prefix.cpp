class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {
       int n=A.size();
        int i=1;
        
        string x=A[0];
        
        while(i<n){
            for(int j=0;j<x.size();j++){
                if(x[j]!=A[i][j]){
                    x.erase(j);
                    break;
                }
            }
            i++;
        }
        return x;
    }
};