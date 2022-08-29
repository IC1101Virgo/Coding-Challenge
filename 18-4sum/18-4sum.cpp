class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=j+1, y=n-1;
                long long tar=target-nums[i]-nums[j];
                while(x<y){
                    if(nums[x]+nums[y]>tar) y--;
                    
                    else if(nums[x]+nums[y]<tar) x++;
                    
                    else{
                        st.insert({nums[i],nums[j],nums[x],nums[y]});
                        x++;
                        y--;
                    }
                }
            }
        }
        
        for(auto x:st){
            res.push_back(x);
        }
        
        return res;
    }
};