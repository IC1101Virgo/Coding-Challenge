class Solution {
public:
    bool wordBreak(string A, vector<string>& B) {
       int n=A.size();
    
    set<string>di;
    
    for(auto x:B){
        di.insert(x);
    }
    
    vector<bool> dp(n+1,0);
    dp[0]=1;
    
     for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                
                if(dp[j]==1){
                    string word=A.substr(j,i-j);
                        
                        if(di.find(word)!=di.end()){
                            dp[i]=1;
                   
                        }
                }
            }
        }
    
    return dp[n];
    }
};