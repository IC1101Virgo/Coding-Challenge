// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> helper(stack<int> s, vector<int>&v){
        if(s.empty()){
        return v;
        }
    
         v.push_back(s.top());
        s.pop();
        
        return helper(s,v);
    
    }
    vector<int> Reverse(stack<int> s){
        vector<int>v;
        
        return helper(s,v);
        
       // return v;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends