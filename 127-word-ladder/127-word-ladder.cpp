class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        
        if(s.find(endWord)==s.end())
            return 0;
        
        queue<string> q;
        
        q.push(beginWord);
        
        int steps=1;
        
        while(!q.empty()){
            int n=q.size();
            
            while(n--){
                string p=q.front();
                q.pop();
                
                if(p==endWord){
                    return steps;
                }
                
                for(int i=0;i<p.size();i++){
                    for(char c='a';c<='z';c++){
                        char x=p[i];
                        p[i]=c;
                        
                        if(s.find(p)!=s.end()){
                            s.erase(p);
                            q.push(p);
                        }
                        
                        p[i]=x;
                    }
                   
                }
                
            }
             steps++;
        }
        
        return 0;
    }
};