// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int B)
    {
        unordered_map<int,int> m;
    
    for(int i=0;i<B;i++)
    m[A[i]]++;
    
    vector<int> v;
    
    v.push_back(m.size());
    
    int start=0;
    for(int i=B;i<n;i++){
        m[A[start]]--;
        m[A[i]]++;
        if(m[A[start]]==0)
        m.erase(A[start]);
        
        start++;
        
       
        
        v.push_back(m.size());
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