class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum=0;
        
        for(auto i:nums)
               sum^=i;
        
        int lowbit=1;
        
        while(true){
    if((lowbit & sum) == 0) lowbit = lowbit<<1;
    else break;
}
        
        vector <int> res(2,0);
        
        for(auto n:nums){
            if(n&lowbit){
                res[0]^=n;
            }
            
            else res[1]^=n;
        }
        
        return res;
    }
};