class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        if(s.find(endWord)==s.end()){
            return 0;
        }
        
        queue<string> q;
            q.push(beginWord);
        int level=1;
        
        while(!q.empty()){
            int ss=q.size();
            
            while(ss--){
                string p=q.front();
                q.pop();
                
                if(p==endWord)
                    return level;
                
                for(int j=0;j<p.size();j++){
                    for(char c='a' ;c<='z';c++){
                        char x=p[j];
                        
                        p[j]=c;
                        
                        if(s.find(p)!=s.end()){
                            s.erase(p);
                            q.push(p);
                        }
                        
                        p[j]=x;
                    }
                }
                
                 
            }
            
            level++;
        }
        
        return 0;
    }
};