int Solution::colorful(int A) {
    int ans;
    
    unordered_map<int,int>m;
    int acc,a;
    
    while(A){
        int acc=1;
        int a=A;
        
        while(a){
            acc*=a%10;
            a/=10;
            if(m[acc]==1) return 0;
            m[acc]=1;
        }
        
        A/=10;
    }
    
    return 1;
    
}
