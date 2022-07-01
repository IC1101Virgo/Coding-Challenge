// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    long int lenOfLongIncSubArr(long int arr[], long int n) {
        
        long int ans=1, temp=1;
        
        for(long int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1])
            temp++;
            
            else temp=1;
            
            ans=max(ans,temp);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        long int arr[n], i;
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        Solution obj;
        cout << obj.lenOfLongIncSubArr(arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends