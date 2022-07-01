// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string s1, string s2) {
        // code here
         unordered_map<char,int> m;
         
         int n=s2.size();
         
         for(int i=0;i<n;i++)
         m[s2[i]]++;
         
         string res="";
         
         for(int i=0;i<s1.size();i++){
             if(m.find(s1[i])!=m.end())
             continue;
             
             else res+=s1[i];
         }
         
         return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}
  // } Driver Code Ends