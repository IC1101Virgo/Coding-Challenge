class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        int n=l.size();
        
        int lo=0, hi=n-1;
        
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            
            if(l[mid]<=t)
                lo=mid+1;
            
            else hi=mid;
        }
        
        return l[lo]>t? l[lo]:l[0];
    }
};