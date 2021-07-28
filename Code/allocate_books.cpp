bool isvalid(vector<int> &A, int B, int mid){
    int pages=0;
    int student=1;
    int n=A.size();
    for(int i=0;i<n;i++){
        pages+=A[i];
        
        if(pages>mid){
        student++;
        pages=A[i];
        }
        
        if(student>B)
        return false;
        
        
    }
    return true;
    
}
int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(B>A.size())
    return -1;
    
    //sort(A.begin(),A.end());
    
    int lo=*max_element(A.begin(),A.end());
    int hi=0;
    
    for(int i=0;i<n;i++)
     hi+=A[i];
    int res=-1;
    
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(isvalid(A,B,mid)){
            
            res=mid;
            hi=mid-1;
        }
        
        else lo=mid+1;
        
    }
    
    return res;
}
