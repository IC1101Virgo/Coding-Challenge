// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        long long required(long long arr[], long long n, long long k) {
        // Your code goes here
        priority_queue<long long> pq;
        
        for(int i=0;i<n;i++)
        pq.push(arr[i]);
        
       long long int ans=pq.top();
       
       if(k<ans)
       return ans-k;
       
       else return -1;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        cout << ob.required(arr, n, k) << endl;
    }
    return 0;
}  // } Driver Code Ends