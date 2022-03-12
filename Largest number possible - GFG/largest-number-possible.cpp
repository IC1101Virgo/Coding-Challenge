// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
       if(S==0 && N>1)
        return "-1";
        string str="";
        int i=0;
        while(i<N && S>0)
        {
            if(S>=9)
            {
                str+="9";
                S-=9;
            }
            else
            {
                str+=to_string(S);
                S=0;
            }
            i++;
        }
        if(S==0)
        {
            while(i<N)
            {
               str+="0";
               i++;
            }
            return str;
        }
        else
        return "-1";
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends