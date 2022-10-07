class Solution {
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) {
         int n=A.size();
    
    int have=0,give=0;
    
    for(int i=0;i<n;i++){
        have+=A[i];
        give+=B[i];
    }
    
    if(have<give)
    return -1;
    
    int curr=0,start=0;
    for(int i=0;i<n;i++){
        if(curr<=0){
            start=i;
            curr=0;
        }
        
        curr+=A[i]-B[i];
    }
    
    return start;
        
    }
};