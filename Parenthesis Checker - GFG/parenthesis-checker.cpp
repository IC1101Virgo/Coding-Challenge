// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        
        int n=x.size();
        
        for(int i=0;i<n;i++){
            if(x[i]==')'){
                if(s.empty())
                return 0;
                else if(s.top()=='(')
                s.pop();
                else return 0;
            }
            
            else if(x[i]==']'){
                if(s.empty())
                return 0;
                else if(s.top()=='[')
                s.pop();
                else return 0;
            }
            
           else if(x[i]=='}'){
                if(s.empty())
                return 0;
                else if(!s.empty() && s.top()=='{')
                s.pop();
                else return 0;
            }
            
            else
            s.push(x[i]);
        }
        
        if(s.empty()) return 1;
        else return 0;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends