class Solution {
public:
    int minSteps(string s, string t) {
        int a=0,b=0;
        
        map<char,int>ms, mt;
        
        for(int i=0;i<s.size();i++)
            ms[s[i]]++;
        
        for(int i=0;i<t.size();i++)
            mt[t[i]]++;
        
        for(int i=0;i<t.size();i++){
            if(ms.find(t[i])==ms.end())
                a++;
        }
        
        for(int i=0;i<s.size();i++){
            if(mt.find(s[i])==mt.end())
                b++;
        }
        
        for(auto x:ms){
            for(auto y:mt){
            if(x.first==y.first && x.second!=y.second)
                a+=abs(x.second-y.second);
            }
        }
        
        return a+b;
    }
};