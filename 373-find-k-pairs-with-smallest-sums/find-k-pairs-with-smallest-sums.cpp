class Solution {
public:
    typedef  pair<int, pair<int,int>> pip;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pip, vector<pip>, greater<pip>> pq;

        int a=nums1[0], b=nums2[0];

        for(int i=0; i<n2; i++){
            pq.push({a+nums2[i], {0, i}});
        }
        
        vector<vector<int>> ans;

        while(!pq.empty() && k!=0){
            auto [x, y] = pq.top();
            pq.pop();

            ans.push_back({nums1[y.first], nums2[y.second]});

            if(y.first +1< n1){
                pq.push({nums1[y.first+1]+nums2[y.second], {y.first+1, y.second}});
            }

            k--;
        }

        return ans;
    }
};