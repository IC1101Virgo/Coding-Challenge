// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        // code here
         unordered_map<int,int>m;
       for(int i=0;i<2*n;i+=2)
       {
          m[arr[i]]=arr[i+1];
       }
       vector<int>vis(31,0);
       queue<int>q;
       q.push(1);
       vis[1]=1;
       int steps=0;
       while(!q.empty())
       {
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               int x=q.front();
               q.pop();
               if(x==30)return steps;
               for(int k=1;k<=6;k++)
               {
                   if(x+k>30)break;
                   if(!vis[k+x])
                   {
                       vis[k+x]=1;
                       if(m.find(k+x)==m.end())
                           q.push(k+x);
                       else
                           q.push(m[k+x]);
                   }    
               }
           }
           steps++;
       }
       return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends