class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        
        vector<int> l(n,-1), r(n,n);
        
        stack<int> left, right;
        
        for(int i=0; i<n; i++){
            while(!left.empty() && h[left.top()]>=h[i])
                left.pop();
            
            if(!left.empty())
                l[i]=left.top();
            
            left.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!right.empty() && h[right.top()]>=h[i])
                right.pop();
            
            if(!right.empty())
                r[i]=right.top();
            
            right.push(i);
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            int x= h[i]*(r[i]-l[i]-1);
            ans=max(ans,x);
        }
        
        return ans;
    }
};