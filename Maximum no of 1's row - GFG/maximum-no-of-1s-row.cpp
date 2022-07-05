// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &arr, int n, int m)
        {
            // your code here
            int ans=-1;
       int min=m;
       for(int i=0;i<n;i++)
       {
           int low =0 , high=m-1;
           while(low<=high)
           {
               int mid=low+(high-low)/2;
               if(arr[i][mid]==0)
               {
                   low=mid+1;
               }
               else
               {
                   high=mid-1;
               }
           }
           if(min>low)
           {
               min=low;
               ans=i;
           }
       }
       return ans;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends