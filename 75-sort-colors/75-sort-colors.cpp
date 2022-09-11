class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
         int i=0, j=0, k=n-1;
        
        while(j<=k){
            if(a[j]==0)
            swap(a[i++],a[j]);
            
             if(a[j]==2)
            swap(a[j],a[k--]);
            
           else j++;
        }
        
        return;
    }
};