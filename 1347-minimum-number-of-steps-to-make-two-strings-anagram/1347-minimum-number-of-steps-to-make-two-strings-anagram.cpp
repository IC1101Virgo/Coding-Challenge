class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();
        
        int freq[26]={0};
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++){
            if(freq[i]>0)
                ans+=freq[i];
        }
        
        return ans;
    }
};