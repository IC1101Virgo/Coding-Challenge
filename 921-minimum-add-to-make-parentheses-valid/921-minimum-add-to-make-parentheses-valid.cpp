class Solution {
public:
    int minAddToMakeValid(string s) {
       int n=s.size();
        int bal=0, res=0;
        for(int i=0;i<n;i++){
            bal+=s[i]=='('?1:-1;
            
            if(bal==-1){
                res++;
                bal++;
            }
        }
        
        return res+bal;
    }
};