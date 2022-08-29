class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        int count=0;
        
        for(auto x:m){
            
            if(k==0)
            {
                if(x.second>1)
                    count++;
                
            }
            
            else{
            if(m.find(x.first+k)!=m.end())
                count++;
            }
        }
        
        return count;
    }
};