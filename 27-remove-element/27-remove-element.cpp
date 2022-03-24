class Solution {
public:
    int removeElement(vector<int>& A, int B) {
         int n=A.size();
    int i=0,j=0;
    for(;i<n && j<n;i++){
        if(A[i]!=B){
            A[j]=A[i];
             j++;
        }
    }
    return j;
    }
};