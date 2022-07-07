// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=1, hi=n;
        int res=0;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(isBadVersion(mid)){
                res=mid;
                hi=mid-1;
            }
            
            else lo=mid+1;
        }
        
        return res;
    }
};

 