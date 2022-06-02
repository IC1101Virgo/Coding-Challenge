class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        
        if(n3==0)
            return 1;
        
        if(n1+n2!=n3)
            return 0;
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 && j==0)
                    dp[i][j]=1;
                
               else if(i==0){
                    if(s2[j-1]==s3[j-1])
                        dp[i][j]=dp[i][j-1];
                }
                
                else if(j==0){
                    if(s1[i-1]==s3[i-1])
                        dp[i][j]=dp[i-1][j];
                }
                
                else if(s1[i-1]!=s3[i+j-1] && s2[j-1]==s3[i+j-1])
                    dp[i][j]=dp[i][j-1];
                
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1])
                    dp[i][j]=dp[i-1][j];
                
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1])
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
        }
        
        return dp[n1][n2];
    }
};