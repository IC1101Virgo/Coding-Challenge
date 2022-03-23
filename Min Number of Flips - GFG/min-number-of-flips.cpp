// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int s = 0 , n = S.length();
   for(int i = 0 ; i < n ; i+=2)
       if(S[i]=='1')
           s++;
   for(int i = 1 ; i < n ; i+=2)
       if(S[i]=='0')
           s++;
   return min(s,n-s);
}