class Solution {
public:
    bool ispal(string s, int i, int j){
       
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            
            else{
                return false;
            }
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        
        int i=0, j=n-1;
        
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            
            else{
                return (ispal(s, i+1,j)||ispal(s,i,j-1));
            }
        }
        
        return true;
    }
};