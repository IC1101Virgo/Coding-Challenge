class Solution {
public:
    int trap(vector<int>& A) {
        int n=A.size();
        
        int i=0, j=n-1;
        if(n<=2)
            return 0;
        
        int lm=A[i],rm=A[j];
        int trapwater=0;
        
        while(i<j){
            if(A[i]<A[j]){
                lm=max(lm,A[i]);
                    trapwater+=lm-A[i];
                i++;
              
            }
            
            else{
                rm=max(rm,A[j]);
                trapwater+=rm-A[j];
              j--;
            }
        }
        
        return trapwater;
    }
};