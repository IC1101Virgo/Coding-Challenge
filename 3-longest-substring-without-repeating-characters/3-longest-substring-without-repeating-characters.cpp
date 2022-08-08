class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        
        unordered_map<char,int> mp;
        int len=0;
        int i=0, j=0;
        int ans=0;
        
       while(i<n){
           while(i<n && mp.find(s[i])==mp.end()){
               mp[s[i]]=i;
               i++;
           }
           
           ans=max(ans,i-j);
           
           int idx=mp[s[i]];
           
           while(j<=idx){
               mp.erase(s[j]);
               j++;
           }
           
           //i++;
       }
        
        return ans;
    }
};