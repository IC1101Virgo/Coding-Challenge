class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        
        int i=0,j=n-1;
        
        while(i<j){
           if(isalnum(s[i])){
               if(isalnum(s[j])){
                   s[i]=tolower(s[i]);
                   s[j]=tolower(s[j]);
                   
                   if(s[i]!=s[j]){
                       return 0;
                   }
                   
                   else i++,j--;
                   
               }
               else j--;
           }
            else i++;
            
        }
        
        return 1;
    }
};