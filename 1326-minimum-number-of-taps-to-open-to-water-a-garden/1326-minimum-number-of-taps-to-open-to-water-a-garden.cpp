class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int size=ranges.size();
        
        vector<int> jumps(n+1,0);
        
        for(int i=0; i<size; i++){
            int l=max(0, i-ranges[i]);
            int r=min(n, i+ranges[i]);
            
            jumps[l]=max(jumps[l], r-l);
        }
        
        int count=0, curend=0, ind=0;
        
        for(int i=0; i<=curend; i++){
            if(i>=n)
                return count;
            
            ind=max(ind, i+jumps[i]);
            
            if(i==curend){
                count++;
                curend=ind;
            }
        }
        
        return -1;
    }
};