class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        
        if(n1+n2!=n3)
            return 0;
        
        if(n3==0)
            return 1;
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
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
                
                else if(s2[j-1]!=s3[i+j-1] && s1[i-1]==s3[i+j-1])
                    dp[i][j]=dp[i-1][j];
                
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1])
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
                else dp[i][j]=0;
            }
        }
        
        return dp[n1][n2];
    }
};