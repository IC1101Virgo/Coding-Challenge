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
    
    for(int i=0;i<2*n;i+=2){
            m[arr[i]]=arr[i+1];
        }

   
    queue<int>q;
    q.push(1);
    vector<int>vis(101,0);
    vis[1]=1;
    int cnt=0;
    while(!q.empty())
    {   
       
        int size=q.size();
        while(size--)
        { 
        int x=q.front(); q.pop();
        if(x==30) return cnt;
        for(int i=0;i<6;i++)
        {    
            int z=x+1+i;
            if(m[z]) z=m[z];
           
           
             if(vis[z]==0 ){ q.push(z); vis[z]=1;}
        }
        }
       cnt++;
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