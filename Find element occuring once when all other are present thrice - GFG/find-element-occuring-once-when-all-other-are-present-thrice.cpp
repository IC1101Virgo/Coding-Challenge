// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int nums[] ,int N) {
        // code here
     int ones=0;
     int twos=0;
     
     for(int i=0;i<N;i++){
         ones=ones^nums[i] & ~twos;
         twos=twos^nums[i] & ~ones;
     }
     
     return ones;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends