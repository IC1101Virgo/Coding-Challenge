class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pMap;
        unordered_map<char, int> cMap;
        vector<int> result;
        
        //create frequency hash map for p string
        for (auto c: p) pMap[c]++;

        for (int i = 0; i < s.size(); i++) {
            cMap[s[i]]++;
            
            //if exceed anagram windows size, remove char at lower-end
            if(i >= p.size()) {
                //eg: psize=3,  0,1,2,3. i@3.  we need to remove 0 so (i-psz) = (3-3) =0
                int l = i - p.size();  
                cMap[s[l]] == 1 ? cMap.erase(s[l]) : cMap[s[l]]--;
            }
            
            //check we have an anagram
            if(cMap == pMap) {
                //eg: psize=3,  0,1,2. i@2 we have anagram from 0 so (i-psz+1) = (2-3+1) =0
                int r = i - p.size() + 1;
                result.push_back(r);
            }
        }
            
        return result;
        
    }
};