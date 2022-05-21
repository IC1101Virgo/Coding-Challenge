class Solution {
public:
    int removeDuplicates(vector<int>& A) {
      int n=A.size();
    int count=0;
    int equals=1;
    for(int i=0;i<n;i++){
        if(i<n-1 && A[i]==A[i+1])
        equals++;
        else {
            A[count]=A[i];
            count++;
            if(equals>=2){
                A[count]=A[i];
                count++;
            }
            equals=1;
        }
    }
    return count;
    }
};