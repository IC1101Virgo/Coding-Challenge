class Solution {
public:
    int titleToNumber(string c) {
        int n=c.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int d=c[i]-'A';
            ans=ans*26+d;
            ans++;
        }
        
        return ans;
    }
};