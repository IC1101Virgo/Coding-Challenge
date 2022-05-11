class Solution {
public:
    #define ll long long
    bool isvalid(vector<int>& b, int m, int k,int mid){
        int n=b.size();
        ll boq=0, ab=0;
        for(int i=0;i<n;i++){
            if(b[i]<=mid){
                ab++;
                if(ab==k){
                    boq++;
                    ab=0;
                }
            }
            else ab=0;
        }
        
        return boq>=m;
    }
    int minDays(vector<int>& b, int m, int k) {
        ll n=b.size();
        
        ll lo=*min_element(b.begin(),b.end());
        ll hi=*max_element(b.begin(),b.end());
        
        int res=-1;
        
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            
            if(isvalid(b,m,k,mid)){
                res=mid;
                hi=mid-1;
            }
            
            else lo=mid+1;
            
        }
        
        return res;
    }
};