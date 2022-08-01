class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        stack<int> s;
        A.push_back(0);
        int ans=0;
        int n=A.size();
   
        for(int i=0;i<n;i++){
            
            while(s.size()>0 && A[s.top()]>A[i])
            {
            int height=A[s.top()];
            s.pop();
            int width= s.size()>0 ? i-1-s.top() : i;
                
            ans = max(ans, height*width);
            }
            
        s.push(i);
   }
        
   return ans;
    }
};