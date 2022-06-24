class Solution {
public:
    vector<int> plusOne(vector<int>& di) {
       int n=di.size();
        
        int carry=1;
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--){
            
            di[i]+=carry;
            ans.push_back(di[i]%10);
            carry=di[i]/10;
            
        }
        
        if(carry!=0)
            ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};