// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long k1, long long k2)
    {
        // Your code goes here
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<N;i++)
        pq.push(A[i]);
        
        int x=k1;
        
        while(--k1)
        pq.pop();
        
        pq.pop();
        long long sum=0;
        
        k2=k2-x;
        while(--(k2)){
            sum+=pq.top();
            pq.pop();
        }
        
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends