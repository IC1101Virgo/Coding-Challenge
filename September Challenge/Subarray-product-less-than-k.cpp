class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& num, int k) {
        if (k==0) return 0;
        int start=0,end=0,p=1,count=0;
        while(end<num.size()){
            p*=num[end];
            while(start<num.size() && p>=k)
            {
                p=p/num[start];
                start++;
            }
            if (p<k)
                count+=end-start+1;
            end++;
        }
        return count;
    }
};