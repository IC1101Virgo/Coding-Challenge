// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int bs(int nums[], int target, int l, int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]<target) l=mid+1;
            
            else r=mid-1;
        }
        
        return -1;
    }
    int search(int nums[], int l, int h, int target){
    //complete the function here
     //int n=nums.size();
        
        int lo=0, hi=h-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(nums[mid]>=nums[hi]) lo=mid+1;
            
            else hi=mid;
        }
        
        int pivot=hi;
        
        return max(bs(nums,target,0,pivot-1),bs(nums,target,pivot,h-1));
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends