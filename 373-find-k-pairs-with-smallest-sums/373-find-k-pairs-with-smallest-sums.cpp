class Solution {
public:
    typedef pair<int,pair<int,int>> pip;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        int n1=nums1.size(), n2=nums2.size();
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        
        for(int i=0;i<n1;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        
        while(ans.size()<k && !pq.empty()){
            pip imp=pq.top();
            
            pq.pop();
            
            int i=imp.second.first, j=imp.second.second;
            
            ans.push_back({nums1[i],nums2[j]});
            
            if(j+1<n2)
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        
        return ans;
    }
};