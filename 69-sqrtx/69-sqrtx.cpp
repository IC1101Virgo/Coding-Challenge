class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        
        int lo=1, hi=x;
        
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            
            if(mid*mid==x)
                return mid;
            
            if(mid*mid<x)
                lo=mid+1;
            
            else hi=mid-1;
        }
        
        return hi;
    }
};