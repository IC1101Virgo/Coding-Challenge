class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        
        int l=0;
        int r=n;
        
        vector<int> v;
        
        for(int i=0;i<n;i++){
            if(s[i]=='I')
                v.push_back(l++);
            
            else v.push_back(r--);
        }
        
        v.push_back(l);
        
        return v;
    }
};