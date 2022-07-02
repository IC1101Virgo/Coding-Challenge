class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_till=nums[0];
        int min_till=nums[0];
        int max_final=nums[0];
        
        for(int i=1;i<n;i++){
            int temp=max({nums[i],nums[i]*max_till,nums[i]*min_till});
            min_till=min({nums[i],nums[i]*max_till,nums[i]*min_till});
            max_till=temp;
            max_final=max(max_final,max_till);
        }
        
        return max_final;
    }
};