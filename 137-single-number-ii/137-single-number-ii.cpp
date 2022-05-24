class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int check, count, ans = 0;
        for(int i=0; i<=31; i++){
            check = 1<<i, count=0;
            for(auto n : nums) if(n & check) count++;
            if(count%3) ans |= check;
        }
        return ans;
        
    }
};