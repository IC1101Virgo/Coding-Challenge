// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}// } Driver Code Ends


vector<int> minAnd2ndMin(int a[], int n) {
      int firstSmallest = INT_MAX;
   int secondSmallest = INT_MAX;
   vector<int> v;
   for(int i=0;i<n;i++)
   {
       if(a[i]<firstSmallest)
       {
           secondSmallest = firstSmallest;
           firstSmallest = a[i];
       }
       else if(a[i]<secondSmallest && firstSmallest != a[i])
       {
           secondSmallest = a[i];
       }
   }
   if(firstSmallest == INT_MAX || secondSmallest == INT_MAX)
   {
       v.push_back(-1);
   }
   v.push_back(firstSmallest);
   v.push_back(secondSmallest);
   return v; 
}