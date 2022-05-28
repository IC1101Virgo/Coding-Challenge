class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        
        unordered_map<char,int> mp;
        
        int ans=0;
        
        while(i<n){
            while(i<n && mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                i++;
            }
            
            ans=max(ans,i-j);
            
            int ind=mp[s[i]];
            
            while(j<=ind){
                mp.erase(s[j++]);
            }
        }
        
        return ans;
    }
};