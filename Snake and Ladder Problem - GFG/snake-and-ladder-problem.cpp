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
        vector<bool>vis(101,0);
        queue<int> q;
        
        q.push(1);
        vis[1]=1;
        int cnt=0;
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                int temp=q.front();
                q.pop();
                
                if(temp==30)
                return cnt;
                
                for(int i=1;i<=6;i++){
                    int z=temp+i;
                    
                    if(m[z])
                    z=m[z];
                    
                    if(vis[z]==0){
                        vis[z]=1;
                        q.push(z);
                    }
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