class Solution {
public:
    int maxScore(vector<int>& A, int B) {
      int n=A.size();
    int sum=0;
    int i=0;
    
    for(i=0;i<B;i++)
    sum+=A[i];
    
    int ans=sum;
    int l=n-1;
    
    while(B--){
        sum=sum-A[B]+A[l];
        l--;
        ans=max(ans,sum);
    }
    
    return ans;
    }
    
};