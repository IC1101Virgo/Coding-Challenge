// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int n=s.size();
        
        string t=s;
        
        reverse(t.begin(),t.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        int ans=INT_MIN;
        string res="";
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                
                if(dp[i][j]>ans){
                    string x=s.substr(i-dp[i][j],dp[i][j]);
                    string y=x;
                    reverse(y.begin(),y.end());
                    if(x==y){
                      res=x;
                      ans=dp[i][j];
                    }
                }
                }
                else dp[i][j]=0;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends