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
           unordered_map<char,int>map1;
           unordered_map<char,int>map2;
           string ans="";
           for(int i =0;i<B.size();i++){
               
               map1[B[i]]++;
           }
           for(int i=0;i<A.size();i++){
               
               map2[A[i]]++;
           }
           
           for(int i=0;i<A.size();i++){
               
               if(map1.find(A[i])==map1.end()){
                   ans=ans+A[i];
                   map1.erase(map1[A[i]]);
               }
               
           }
           for(int i=0;i<B.size();i++){
               
               if(map2.find(B[i])==map2.end()){
                   ans=ans+B[i];
                   map2.erase(map2[B[i]]);
               }
               
           }
           if(ans.empty()){
               return "-1";
           }
           sort(ans.begin(),ans.end());
           return ans;
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