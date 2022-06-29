// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        string t = "";
stack<int> st;

for(int i=0;i<=s.length();i++){
st.push(i+1);

if(s.length()==i || s[i]=='I' ){
while(!st.empty()){
t += to_string(st.top());
st.pop();
}
}
}
return t;
       
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends