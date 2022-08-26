class Solution {
public:
    typedef pair<int,int> pip;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int n=arr.size();
        
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        
        for(int i=0;i<arr.size();i++)
            pq.push({abs(arr[i]-x),arr[i]});
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};