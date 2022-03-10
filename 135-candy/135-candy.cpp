class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> v1(n,1),v2(n,1);
        
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1])
                v1[i]=1+v1[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1])
                v2[i]=1+v2[i+1];
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=max(v1[i],v2[i]);
        }
        
        return ans;
    }
};