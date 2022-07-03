class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
         int n=matrix.size();
        int m=matrix[0].size();
        int dp[n+1][m+1];//2-ddp for prefix sum
       
       
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else{
                    
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];//using prefix dp formulae
                    
                }
            }
        }
        int count=0;
		//generate all possible sub matrix.
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=i;k<=n;k++)
                {
                    for(int l=j;l<=m;l++)
                    {
                      int ans=dp[i-1][j-1]+dp[k][l]-dp[i-1][l]-dp[k][j-1];
                        if(ans==target)
                        {
                            count++;
                        }
                    }
                    
                }
                
            }
        }
        return count;
       
    }
};