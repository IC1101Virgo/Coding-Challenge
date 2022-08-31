class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
         int n=h.size();
        
        stack<int> l, r;
        
        vector<int> left(n,-1), right(n,n);
        
        for(int i=0; i<n; i++){
            while(!l.empty() && h[l.top()]>=h[i])
                l.pop();
            
            if(!l.empty()){
                left[i]=l.top();
            }
            
            l.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!r.empty() && h[r.top()]>=h[i])
                r.pop();
            
            if(!r.empty()){
                right[i]=r.top();
            }
            
            r.push(i);
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            int temp=h[i]*(right[i]-left[i]-1);
            ans=max(ans,temp);
        }
        
        return ans;
        
        
    }
};