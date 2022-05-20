class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        int count=0;
        
        
        
        for(auto x:m){
            
            if(k==0){
                if(x.second>1)
                    count++;
            }
            
            else{
            int r=x.first+k;
            
            if(m.find(r)!=m.end())
                count++;
            }
        }
        
        return count;
        
    }
};