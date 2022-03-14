class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        
        for(auto &it:tasks){
            freq[it-'A']++;
        }
        
        sort(freq.begin(),freq.end());
        int max_v=freq[25]-1;
            int idel=max_v*n;
        
        for(int i=24;i>=0;i--){
            idel-=min(freq[i],max_v);
        }
        
        return idel>0?idel+tasks.size():tasks.size();
    }
};