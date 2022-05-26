class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;
        
        for(int k=0;k<n;k++){
           
            int i=k+1,j=n-1;
            
            while(i<j){
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==0){
                    
                    st.insert({nums[i],nums[j],nums[k]});

                    i++;
                    j--;
                }
                
               else  if(sum<0) i++;
                
                else j--;
            }
        }
        
        for(auto i:st)
            res.push_back(i);
        
        return res;
    }
};