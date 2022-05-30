class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        
        for(int i=0;i<t.size();i++)
            tmap[t[i]]++;
        
        int end=0, start=0, count=t.size(), maxlen=INT_MAX, lo=0;
        
        while(end<s.size()){
            if(tmap[s[end]]>0){
                count--;
            }
            
            tmap[s[end]]--;
            
            end++;
            
            while(count==0){
                if(end-start<maxlen){
                    lo=start;
                    maxlen=end-start;
                }
                
                tmap[s[start]]++;
                
                if(tmap[s[start]]>0)
                count++;
                
                start++;
            }
        }
        
         if(maxlen!=INT_MAX){
            return s.substr(lo,maxlen);
        }
        return "";
        
    }
};