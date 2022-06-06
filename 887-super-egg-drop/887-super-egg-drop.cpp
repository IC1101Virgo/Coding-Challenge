class Solution {
public:
   
       int helper(int k, int n, vector<vector<int>> &memo){
    if(k==1)
    return n;
    
    if(n==0||n==1)
    return n;
    
    if(memo[k][n]!=-1) return memo[k][n];
    
    int temp=0, lo=0,hi=n, mn=INT_MAX;
    
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        int left=helper(k-1,mid-1,memo);
        int right=helper(k,n-mid,memo);
        
        temp=1+max(left,right);
        
        if(left<right)
        lo=mid+1;
        
        else hi=mid-1;
        
        mn=min(mn,temp);
    }
    
    return memo[k][n]=mn;
}
    int superEggDrop(int k, int n) {
         vector<vector<int>> memo(k+1,vector<int>(n+1,-1));
    return helper(k,n,memo);
    }
};