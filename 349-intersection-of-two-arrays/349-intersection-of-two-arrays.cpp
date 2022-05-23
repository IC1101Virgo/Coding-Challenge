class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        
        for(auto val:nums2)
            s2.insert(val);
        
        vector<int> res;
        for(auto val1:s1){
            if(s2.find(val1)!=s2.end())
                res.push_back(val1);
        }
        
        return res;
    }
};