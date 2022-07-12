// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
         unordered_map<char,int> tmap;
        
        for(int i=0;i<t.size();i++)
            tmap[t[i]]++;
        
        int end=0, start=0, count=t.size(), maxlen=INT_MAX, lo=0;
        
        while(end<s.size()){
            if(tmap[s[end]]>0){
                count--;
            }
            
            tmap[s[end]]--;
            
            end++;
            
            while(count==0){
                if(end-start<maxlen){
                    lo=start;
                    maxlen=end-start;
                }
                
                tmap[s[start]]++;
                
                if(tmap[s[start]]>0)
                count++;
                
                start++;
            }
        }
        
         if(maxlen!=INT_MAX){
            return s.substr(lo,maxlen);
        }
        return "-1";
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