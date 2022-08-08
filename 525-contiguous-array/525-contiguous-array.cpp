class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int>m;
        int sum=0;
        int max_len=0;
        
        for(int i=0; i<n; i++){
            nums[i]=nums[i]==0?-1:1;
            
            sum+=nums[i];
            
            if(sum==0){
                max_len=max(i+1,max_len);
            }
            
            if(m.find(sum)!=m.end()){
                int len= i-m[sum];
                max_len=max(max_len,len);
            }
            
            if(m.find(sum)==m.end())
            m[sum]=i;
        }
        
        return max_len;
    }
};