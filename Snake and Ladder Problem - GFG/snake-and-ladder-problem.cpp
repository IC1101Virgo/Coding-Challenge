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
        
        queue<int> q;
        vector<int> vis(31,0);
        
        q.push(1);
        vis[1]=1;
        int steps=0;
        
        while(!q.empty()){
           int size=q.size();
            
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                
                if(x==30) return steps;
                
                for(int j=1;j<=6;j++){
                    if(x+j>30) break;
                    
                    if(vis[x+j]==0){
                        vis[x+j]=1;
                        if(m.find(x+j)==m.end())
                        q.push(x+j);
                        else q.push(m[x+j]);
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