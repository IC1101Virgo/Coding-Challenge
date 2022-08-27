class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(), t.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        string ans="";
        int val=INT_MIN;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    
                    if(val<dp[i][j]){
                    string x= s.substr(i-dp[i][j], dp[i][j]);
                    
                    string xx=x;
                    reverse(xx.begin(), xx.end());
                    
                    if(x==xx){
                        if(x.size()>ans.size()){
                            ans=x;
                            val=x.size();
                        }
                    }
                    }
                }
            }
        }
        
        return ans;
    }
};