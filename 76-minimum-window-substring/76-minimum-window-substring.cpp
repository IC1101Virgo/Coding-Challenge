class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), mt=t.size();
        
        unordered_map<int,int> m;
        
        for(auto x:t)
            m[x]++;
        
        int cnt=m.size();
        int i=0, j=0;
        
        int len=INT_MAX;
        string ans="";
        
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                
                if(m[s[j]]==0)
                    cnt--;
                
              //  j++;
            }
            
            while(cnt==0){
                if(len>j-i+1){
                    len=j-i+1;
                    ans=s.substr(i,len);
                }
                
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    
                    if(m[s[i]]==1)
                        cnt++;
                }
                i++;
            }
            
            j++;
        }
        
        return len==INT_MAX?"":ans;
    }
};