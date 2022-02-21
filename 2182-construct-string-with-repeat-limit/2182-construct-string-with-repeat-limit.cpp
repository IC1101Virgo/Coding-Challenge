class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        map<char,int, greater<int>>m;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        
        string res;
        
        while(!m.empty()){
            int freq=m.begin()->second;
            int c=0;
            char ch=m.begin()->first;
            m.erase(m.begin());
            while(freq!=0){
                c++;
                if(c>limit){
                    if(m.empty())
                        return res;
                    res.push_back(m.begin()->first);
                    m.begin()->second--;
                    if(m.begin()->second == 0) m.erase(m.begin());
                    c = 1;
                }
                res.push_back(ch);
                freq--;
            }
        }
         return res;
    }
};