class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        
        int i=0, j=n-1;
        int ans=INT_MIN;
        
        while(i<=j){
            int x= min(h[i], h[j])*(j-i);
            
            ans=max(ans, x);
            
            if(h[i]<h[j])
                i++;
            
            else j--;
        }
        
        return ans;
    }
};