class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> s(deadends.begin(),deadends.end());
        set<string> vis;
        
        int ans=0;
        if(s.find("0000")!=s.end())
            return -1;
        
        queue<string> q;
        q.push("0000");
       
        vis.insert("0000");
        
        
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                auto prime=q.front();
                q.pop();
                
                if(prime==target)
                    return ans;
                
                for(int i=0;i<4;i++){
                    char temp=prime[i];
                    
                    if(prime[i]=='9'){
                        prime[i]='0';
                    }
                    
                    else prime[i]=temp+1;
                    
                    if(s.find(prime)==s.end() && vis.find(prime)==vis.end()){
                        vis.insert(prime);
                        q.push(prime);
                    }
                    
                    prime[i]=temp;
                    
                    if(prime[i]=='0'){
                        prime[i]='9';
                    }
                    
                    else prime[i]=temp-1;
                    
                    if(s.find(prime)==s.end() && vis.find(prime)==vis.end()){
                        vis.insert(prime);
                        q.push(prime);
                    }
                    
                    prime[i]=temp;
                    
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};