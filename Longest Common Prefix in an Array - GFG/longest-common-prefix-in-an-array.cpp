// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string x;
        x=arr[0];
        int i=1;
        
        while(i<N){
            for(int j=0;j<x.size();j++){
                if(x[j]!=arr[i][j])
                {
                    x.erase(j);
                    break;
                }
            }
            i++;
        }
        
        if(x.size()==0)
        return "-1";
        
        return x;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends