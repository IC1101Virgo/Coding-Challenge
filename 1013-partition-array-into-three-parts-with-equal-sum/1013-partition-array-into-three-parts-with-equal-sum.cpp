class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int ans=0;
        
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
        }
        
        if(ans%3!=0)
            return false;
        
        int count=0;
        if(ans%3==0){
            
            int part=0;
            for(auto x:arr){
                part+=x;
                
                if(part==ans/3){
                    part=0;
                    count++;
                }
            }
        }
        
        return count>=3?true:false;
    }
};