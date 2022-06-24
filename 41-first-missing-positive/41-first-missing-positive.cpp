class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        
        for(int i=0;i<n;i++){
            while(A[i]>0 && A[i]<n+1 && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
        }
        
        for(int i=0;i<n;i++){
            if(A[i]!=i+1)
                return i+1;
        }
        
        return n+1;
    }
};