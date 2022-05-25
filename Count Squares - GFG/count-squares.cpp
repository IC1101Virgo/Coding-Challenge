// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
       int l=1,r=N,mid,ans=0;
        
        while(l<=r)
        {
            mid = l+(r-l)/2;
            long long y = (long long)mid*mid;
            
            if(y<N)
            {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends