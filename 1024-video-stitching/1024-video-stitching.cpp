class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int t) {
        sort(clips.begin(), clips.end());
        
        int s=0, r=0, jump=0;
        
        while(s<t){
            for(auto x:clips){
                if(s>=x[0] && s<=x[1])
                    r=max(r,x[1]);
            }
            
            if(s==r)
                return -1;
            
            jump++;
            
            s=r;
        }
        
        return jump;
    }
};