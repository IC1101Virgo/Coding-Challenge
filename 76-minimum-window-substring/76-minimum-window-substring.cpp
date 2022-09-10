class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), mt=t.size();
        
        unordered_map<int,int> m;
        
        for(auto x:t)
            m[x]++;
        
        int count=m.size();
        int i=0, j=0;
        
        int len=INT_MAX;
        string ans="";
        
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                
                if(m[s[j]]==0)
                    count--;
            }
            
            while(count==0){
                if(len>j-i){
                    len=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
                
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    
                    if(m[s[i]]==1)
                        count++;
                }
                i++;
            }
            j++;
            
        }
        
        return len==INT_MAX?"":ans;
    }
};