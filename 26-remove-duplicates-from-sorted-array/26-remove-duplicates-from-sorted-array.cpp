class Solution {
public:
    int removeDuplicates(vector<int>& A) {
       int n=A.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(i<n-1 && A[i]==A[i+1]) continue;
        
        else{
            A[count]=A[i];
            count++;
        }
    }
    
    return count;
    }
};