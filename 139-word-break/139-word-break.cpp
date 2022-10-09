class Solution {
public:
    bool wordBreak(string a, vector<string>& b) {
        set<string> di (b.begin(), b.end());
        int n=a.size();
        
        // for(auto x:b)
        //     di.insert(x);
        
        vector<int> dp(n+1, 0);
        dp[0]=1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j]==1){
                    string word= a.substr(j, i-j);
                    if(di.find(word)!=di.end())
                        dp[i]=1;
                }
            }
        }
        
        return dp[n];
    }
};