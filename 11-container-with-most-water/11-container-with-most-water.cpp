class Solution {
public:
    int maxArea(vector<int>& A) {
      int n=A.size();
        
      int maxx=INT_MIN;
      int ans=INT_MIN;
        int i=0, j=n-1;
        
        while(i<j){
            maxx=min(A[i],A[j])*(j-i);
            ans=max(ans,maxx);
            
            if(A[i]>A[j])
                j--;
            
            else i++;
            
        }
        
        return ans;
    }
};