class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        
        stack<int> left,right;
        vector<int> l(n, -1), r(n, n);
        
        for(int i=0;i<n;i++){
            while(!left.empty() && h[left.top()]>=h[i])
                left.pop();
            
            if(!left.empty())
                l[i]=left.top();
            
            left.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!right.empty() && h[right.top()]>=h[i])
                right.pop();
            
            if(! right.empty())
               r[i]= right.top();
            
            right.push(i);
        }
        
        int ans=INT_MIN, maxa=INT_MIN;
        
        for(int i=0;i<n;i++){
            ans=h[i]*(r[i]-l[i]-1);
            maxa=max(maxa,ans);
        }
        
        return maxa;
    }
};