class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        
        int n=s.length(), len=INT_MIN, j=0, i=0;
        
        if(n==0)
            return 0;
        
        while(i<n){
            while(i<n && m.find(s[i])==m.end()){
                m[s[i]]=i;
                i++;
            }
            
            len=max(len,i-j);
            
            int index=m[s[i]];
            
            if(j<=index){
                m.erase(s[j++]);
            }
        }
        
        return len;
    }
};