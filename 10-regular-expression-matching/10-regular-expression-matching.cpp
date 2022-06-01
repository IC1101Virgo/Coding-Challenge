class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        
        dp[0][0]=1;
        
       
        
         for(int j=1;j<=m;j++){
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-2];
            
            else dp[0][j]=0;
        } 
        
        for(int i=1; i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];
                    
                    if(s[i-1]==p[j-2]|| p[j-2]=='.')
                        dp[i][j]=dp[i-1][j]||dp[i][j];
                }
                
                else if(s[i-1]==p[j-1]||p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                
               
            }
        }
        
        return dp[n][m];
    }
};