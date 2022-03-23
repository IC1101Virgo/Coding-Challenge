// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



string merge (string S1, string S2)
{
    // your code here
    
    string S="";
    int n1=S1.size();
    int n2=S2.size();
    int i=0,j=0;
     for(int k=0; k<n1+n2; k++)
     {  
         if(i<n1)
         {
           S+=S1[i];
         }
         if(j<n2)
         {
           S+=S2[i];
         }
         i++;
         j++;
     }
     return S;
}