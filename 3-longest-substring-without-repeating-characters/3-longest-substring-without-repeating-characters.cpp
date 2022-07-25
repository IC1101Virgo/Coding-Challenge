class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        
        unordered_map<char,int> m;
        
        int i=0, j=0;
        
        int ans=0;
        
        while(i<n){
            while(i<n && m.find(s[i])==m.end()){
                m[s[i]]=i;
                i++;
            }
            
            ans=max(ans,i-j);
            
            int idx=m[s[i]];
            
            while(j<=idx){
                m.erase(s[j]);
                j++;
            }
            
           // i++;
        }
        
        return ans;
        
    }
};