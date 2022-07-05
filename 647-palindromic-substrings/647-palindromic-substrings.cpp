class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(), a[n][n], ans=0;
        
        memset(a,0,sizeof(a));
        
        for(int i=0;i<n;i++)
            a[i][i]=1,ans++;
        
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])
            {
                a[i-1][i]=1;
                ans++;
            }
        }
        
        for(int size=3;size<=n;size++)
        {
            for(int j=0;j<n-size+1;j++)
            {
                if(s[j]==s[j+size-1] && a[j+1][j+size-2]==1) a[j][j+size-1]=1,ans++;
            }
        }
        
        return ans;
    }
};