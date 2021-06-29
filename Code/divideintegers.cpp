int Solution::divide(int A, int B) {
    if(B==0) return INT_MAX;
    if(A==0) return 0;
    if(B==1) return A;
    //if(A==2147483647 && B==1) return 2147483647;
    if(A==-2147483648 && B==-1) return 2147483647;
    int sign =(A<0)^(B<0)==0 ?1:-1;
    int ans=0;
    
    A=abs(A);
    B=abs(B);
    
    while(A-B>=0){
        ans++;
        A=A-B;
    }
    
    return ans*sign;
}
