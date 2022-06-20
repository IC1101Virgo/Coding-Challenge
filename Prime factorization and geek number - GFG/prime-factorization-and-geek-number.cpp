// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    int geekNumber(int N){
        // code here
         int flag=2,fac1,fac2;
       for(int i=2;i<=sqrt(N);i++)
       {
           if(N%i==0)
           {
               fac1=i;
               fac2=N/i;
               
               if(fac2%fac1==0){
               return 0;
               }
               
           }
       }
       return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        if(ob.geekNumber(N))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends