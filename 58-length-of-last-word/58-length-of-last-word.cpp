class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        
        int i=n-1, j=0;
        
        while(i>=0 && s[i]==' ')
            i--;
        
        while(i>=0 && s[i]!=' ')
        {
            j++;
            i--;
        }
        
        return j;
    }
};