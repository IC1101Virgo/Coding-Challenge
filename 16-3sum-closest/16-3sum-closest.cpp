class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int m=INT_MAX,ans;
        int N=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<N;i++){
            int s=i+1,l=N-1;
            while(s<l){
                int b=nums[s]+nums[l];
                if(m > abs(t-(b+nums[i]))){
                    m = abs(t-(b+nums[i]));
                    ans = b+nums[i];
                }
                if(b == t-nums[i]) return t;
                else if(b < t-nums[i]) s++;
                else l--;
            }
        }
        return ans;
    }
};