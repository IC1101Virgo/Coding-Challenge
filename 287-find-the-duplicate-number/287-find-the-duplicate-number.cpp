class Solution {
public:
    int findDuplicate(vector<int>& A) {
       int n=A.size();
        
        for(int i=0;i<n;i++){
            if(A[abs(A[i])-1]>0)
                A[abs(A[i])-1]*=-1;
            
            else return abs(A[i]);
        }
        
        return -1;
    }
};