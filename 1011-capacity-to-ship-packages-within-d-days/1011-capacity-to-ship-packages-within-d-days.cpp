class Solution {
public:
    bool isvalid(vector<int>& w, int d, int mid, int n){
        int sum=0, fac=1;
        
        for(int i=0;i<n;i++){
            sum+=w[i];
            
            if(sum>mid){
                fac++;
                sum=w[i];
            }
            
            if(fac>d)
                return false;
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int n=w.size();
        
        int hi=0,lo=0;
        
        for(auto x:w){
            hi+=x;
            lo=max(lo,x);
        }
        
        int res=-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(isvalid(w,d,mid,n)){
                res=mid;
                hi=mid-1;
            }
            
            else lo=mid+1;
        }
        
        return res;
    }
};