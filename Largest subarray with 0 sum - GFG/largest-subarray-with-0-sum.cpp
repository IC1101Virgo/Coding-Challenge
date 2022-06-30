// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        unordered_map<int,int> m;
        
        int s=-1,e=-1,sum=0, ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            
            if(sum==0)
            ans=max(ans,i+1);
            
           else if(m.find(sum)!=m.end()){
                ans=max(ans,i-m[sum]);
            }
            
            else m[sum]=i;
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends