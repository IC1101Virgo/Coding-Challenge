// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n=s.length(), ml=p.length();
        
        unordered_map<char,int>mpp;
        
        for(int i=0;i<ml;i++)
        mpp[p[i]]++;
        
        int count=mpp.size();
       int j=0,i=0,start;
       string ans="";
       int len=INT_MAX;
       
       while(j<s.length()){
           
           if(mpp.find(s[j])!=mpp.end()){
               mpp[s[j]]--;
               if(mpp[s[j]]==0){
                   count--;
               }
           }
           
           while(count==0){
               if(len>j-i+1){
                   len=j-i+1;
                   ans=s.substr(i,len);
               }
               if(mpp.find(s[i])!=mpp.end()){
                   mpp[s[i]]++;
                   if(mpp[s[i]]==1)count++;
               }
               i++;
           }
           
           j++;
       }
       return len!=INT_MAX ? ans : "-1" ;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends