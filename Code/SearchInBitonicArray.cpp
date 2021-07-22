int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int lo=0, hi=n-1;
    
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(A[mid]==B)
        return mid;
        
        else if(A[mid]>B){
            if(A[mid+1]<A[mid])
            lo=mid+1;
            else
            hi=mid-1;
        }
        
        else{
            if(A[mid+1]<A[mid])
            hi=mid-1;
            else
            lo=mid+1;
        }
    }
    
    return -1;
}
