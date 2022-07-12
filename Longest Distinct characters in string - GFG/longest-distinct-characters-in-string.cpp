// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.size();
    unordered_map<int,int> m;
    
    int i=0,j=0;
    int ans=0;
    
    while(j<n){
        while(j<n && m.find(s[j])==m.end()){
            m[s[j]]=j;
            j++;
        }
        
        ans=max(ans,j-i);
        
        int ind=m[s[j]];
        
        while(i<=ind){
            m.erase(s[i]);
            i++;
        }
    }
    
    return ans;
    
}