class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        int fb=INT_MAX,fp=INT_MIN, sb=INT_MAX, sp=INT_MIN;
        
        for(int i=0;i<n;i++){
            fb=min(fb,p[i]);
            fp=max(fp,p[i]-fb);
            sb=min(sb,p[i]-fp);
            sp=max(sp,p[i]-sb);
        }
        
        return sp;
    }
};