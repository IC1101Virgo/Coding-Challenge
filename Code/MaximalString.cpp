void helper(string &A,int B, string &ans){
    if(B==0)
    return;
    
    for(int i=0;i<A.length();i++){
        for(int j=0;j<A.length();j++){
            swap(A[i],A[j]);
            if(A>=ans) ans=A;
            
            helper(A,B-1,ans);
            swap(A[i],A[j]);
        }
    }
}
string Solution::solve(string A, int B) {
    string ans=A;
    helper(A,B,ans);
    
    return ans;
}
