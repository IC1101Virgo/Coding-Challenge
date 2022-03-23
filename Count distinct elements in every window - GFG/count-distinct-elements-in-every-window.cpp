// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
         unordered_map<int,int>um;
        vector<int>v;
        for(int i=0;i<k;i++){
            um[A[i]]++;
        }
        v.push_back(um.size());
        int j=0;
        for(int i=k;i<n;i++){
            um[A[j]]--;
            um[A[i]]++;
            if(um[A[j]]==0){
                um.erase(A[j]);
            }
            j++;
            v.push_back(um.size());
        }
        
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends