class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        
        int n=time.size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            int t=time[i];
            cnt+=mp[(60-t%60)%60];
            mp[t%60]++;
        }
        
        return cnt;
        
    }
};
