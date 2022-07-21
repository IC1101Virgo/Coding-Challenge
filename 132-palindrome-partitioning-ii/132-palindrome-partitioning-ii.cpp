class Solution {
public:
     bool ispal(string &str,int i, int j){
        //int i=0, j=str.size()-1;
        
        while(i<=j){
            if(str[i]!=str[j])
                return 0;
            
            else{
                i++;
                j--;
            }
        }
        
        return 1;
    }
    int solve(string s, vector<vector<int>> &dp, int i, int j){
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(ispal(s,i,j)){
            dp[i][j]=0;
                return 0;
        }
        
        int minc=INT_MAX;
        
        for(int k=i;k<=j;k++){
            if(ispal(s,i,k)){
                int temp=1+solve(s,dp,k+1,j);
                minc=min(minc,temp);
            }
        }
        
        return dp[i][j]=minc;
        
    }
    int minCut(string s) {
        int n=s.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(s,dp,0,n-1);
    }
};