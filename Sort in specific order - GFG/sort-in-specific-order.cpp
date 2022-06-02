// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    void sortIt(long long arr[], long long n)
    {
        //code here.
         int i;
       vector<long long int> vc;
       stack<long long int> st;
       sort(arr,arr+n);
       
       for(i=0;i<n;i++){
           if(arr[i]%2 ==1){
               st.push(arr[i]);
           }
           else
           {
               vc.push_back(arr[i]);
           }
       }
       int size=st.size();
       for(i=0;i<size;i++){
           arr[i]=st.top();
           st.pop();
           
       }
       int j=0;
       for(i=size;i<n;i++){
           arr[i]=vc[j];
           j++;
       }
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        Solution ob;
        ob.sortIt(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends