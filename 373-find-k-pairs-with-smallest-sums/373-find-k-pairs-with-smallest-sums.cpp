class Solution {
public:
    typedef pair<int, pair<int,int>> pip;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        int n1=nums1.size(), n2=nums2.size();
        
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        
        for(int i=0; i<n2; i++){
            pq.push({nums1[0]+nums2[i], {0, i}});
        }
        
        while(ans.size()<k && !pq.empty()){
            auto prime=pq.top();
            pq.pop();
            int i=prime.second.first, j=prime.second.second;
            
            ans.push_back({nums1[i], nums2[j]});
            
            if(i+1<n1){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
            }
        }
        
        return ans;
    }
};