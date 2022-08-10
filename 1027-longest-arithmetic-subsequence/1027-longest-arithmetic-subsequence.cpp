class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        
        if(n<3)
            return n;
        
        int ans=2;
        
        vector<unordered_map<int,int>> dp(n);
        
        for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = A[j]-A[i];
            if( dp[j].find(diff)!=dp[j].end()){
                dp[i][diff] = dp[j][diff]+1;
                ans=max(ans,dp[i][diff] );
            }
            else{
                 dp[i][diff] = 2;
                //ans=max(ans,dp[i][diff] );
            }
        }
    }
        
        return ans;
    }
};