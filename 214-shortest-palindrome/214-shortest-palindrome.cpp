class Solution {
public:
    int makelps(string s){
         int n=s.size();
        int lps[n];
        int i=1, len=0;
        
        lps[0]=0;
        
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            
            else{
                if(len!=0) len=lps[len-1];
                
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
       
       
        
        string rev=s;
        
        reverse(rev.begin(),rev.end());
        
        int x= makelps(s+'#'+rev);
        
         return rev.substr(0, rev.length()-x) + s;
        
    }
};