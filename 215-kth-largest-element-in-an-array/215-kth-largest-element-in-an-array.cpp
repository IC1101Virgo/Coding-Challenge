class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            pq.push(nums[i]);
        
        int ans=0;
        while(k!=1){
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};