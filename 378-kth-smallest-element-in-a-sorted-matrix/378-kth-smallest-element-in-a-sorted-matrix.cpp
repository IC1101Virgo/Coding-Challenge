class Solution {
public:
    int bs(vector<vector<int>>& mat, int mid){
        int count = 0, n = mat.size(), i = n-1, j = 0;
        while(i >= 0 && j < n){
            if(mat[i][j] > mid) i--;
            else{
                count += (i+1);
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
      int n=mat.size();
        
        int start=mat[0][0], end=mat[n-1][n-1];
        int mid;
        while(start<end){
            mid=start+(end-start)/2;
            
            int num=bs(mat,mid);
            
            if(num<k) start=mid+1;
            
        else end=mid;
        }
        
        return start;
    }
};