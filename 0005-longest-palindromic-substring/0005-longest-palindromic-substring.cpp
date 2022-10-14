class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int mx = 0;
        
        for(int ind=0; ind<n; ind++){
            int len = 1;
            int i = ind-1, j = ind+1;
            while(i>=0 && i<n && j>=0 && j<n && s[i] == s[j]){
                i--; j++; len+=2;
            }
            if(len > mx){
                mx = len;
                ans = s.substr( i+1, len );
            }
            i = ind; j = ind+1;
            len = 0;
            while(i>=0 && i<n && j>=0 && j<n && s[i] == s[j]){
                i--; j++; len+=2;
            }
            if(len > mx){
                mx = len;
                ans = s.substr( i+1, len );
            }
            
        }
        return ans;
    }
};