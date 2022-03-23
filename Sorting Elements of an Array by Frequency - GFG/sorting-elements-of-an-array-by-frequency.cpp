#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++)
    {
        cin>>arr[i];
    }
    vector<int> v;
    for(int i=0; i<n; i++)
    v.push_back(arr[i]);
    
    priority_queue<pair<int,int>> maxh;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        mp[v[i]]++;
    }
    
    sort(v.begin(),v.end(),[&](int a,int b){
        return mp[a]!=mp[b] ? mp[a]<mp[b] : a>b;
    });
    
    reverse(v.begin(),v.end());
    
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
    
    
    
    
    
    
}
return 0;
}