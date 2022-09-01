class Solution {
public:
    vector<int> v, ori;
    
    Solution(vector<int>& nums) {
        v=nums;
        ori=nums;
    }
    
    vector<int> reset() {
        return ori;
    }
    
    vector<int> shuffle() {
        int n=v.size();
        int a= rand()%n, b=rand()%n;
        
        swap(v[a],v[b]);
        
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */