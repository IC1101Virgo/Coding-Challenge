// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	      unordered_map<int,int> m;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        int count=0;
        
        for(auto x:m){
            
            if(k==0)
            {
                if(x.second>1)
                    count++;
                
            }
            
            else{
            if(m.find(x.first+k)!=m.end())
                count++;
            }
        }
        
        return count;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends