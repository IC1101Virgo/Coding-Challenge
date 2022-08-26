class Solution {
public:
         typedef pair<int,pair<int,int>> pip;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        int n=nums1.size(), m=nums2.size();
        
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({nums2[0]+nums1[i], {0,i}});
        }
        
        while(res.size()<k && !pq.empty()){
            auto [x,y]= pq.top();
            pq.pop();
            
            int a=y.first, b=y.second;
            
            res.push_back({nums1[b],nums2[a]});
            
            
            if(a+1<m){
                pq.push({nums2[a+1]+nums1[b],{a+1,b}});
            }
        }
        
        return res;
                
    }
};