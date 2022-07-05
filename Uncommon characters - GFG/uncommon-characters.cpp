// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            string s="";
            int map2[256] = {0};
            int map1[256] = {0};
            
            for(int i=0;i<A.size();i++)
            {
               map1[A[i]] = 1; 
            }
            
            for(int i=0;i<B.size();i++)
            {
              map2[B[i]]=1;
              
            }
            
            for(int i=0;i<256;i++)
            {
                if(map1[i] ^ map2[i] ) s+=char(i);
            }
            
            if(s.empty()) return "-1";
            return s;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends