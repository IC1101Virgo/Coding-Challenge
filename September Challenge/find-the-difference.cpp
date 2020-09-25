class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length;i++)
            mp[s[i]]++;
        for(int i=0;i<t.length;i++)
        {
            if(!mp.count(t[i])) return t[i];
            if(mp.count(t[i]) && mp[t[i]]==0)
                return 0;
            mp[t[i]]--;
        }
        
    }

};