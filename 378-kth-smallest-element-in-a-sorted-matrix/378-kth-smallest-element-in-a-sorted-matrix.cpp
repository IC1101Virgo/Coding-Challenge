class Solution {
public:
    int solve(vector<vector<int>>& mat, int mid){
        int n=mat.size(), i=n-1,j=0;
        
        int count=0;
        
        while(i>=0 && j<n){
            if(mat[i][j]>mid) i--;
            
            else{
                count+=(i+1);
                j++;
            }
        }
        
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        
        int lo=mat[0][0], hi=mat[n-1][n-1];
        
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            
            int pos=solve(mat,mid);
            
            if(pos<k) lo=mid+1;
            
            else hi=mid;
        }
        
        return lo;
    }
};