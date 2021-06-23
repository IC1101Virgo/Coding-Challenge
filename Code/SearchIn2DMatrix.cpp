int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n=A.size(),m=A[0].size();
    
    int s=0,e=(n*m)-1,mid;
    
    while(s<=e){
        mid=s+(e-s)/2;
        int i=mid/m,j=mid%m;
        
        if(A[i][j]==B) return 1;
        
        else if(A[i][j]<B) s=mid+1;
        
        else e=mid-1;
    }
    
    return 0;
}
