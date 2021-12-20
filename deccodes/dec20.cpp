class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         int n=arr.size();
        vector<int>pair;
        vector<vector<int>> sol;
        
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        
        for(int i=1;i<n;i++){
           int diff= abs(arr[i]-arr[i-1]);
           mini=min(diff,mini);
        }
        
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])==mini)
            {
                pair.push_back(arr[i-1]);
                pair.push_back(arr[i]);
                    sol.push_back(pair);
                pair.clear();
            }
        }
        
        
        return sol;
    }
};
