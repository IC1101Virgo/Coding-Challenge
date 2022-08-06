class Solution {
public:
    typedef pair<int,char> pip;
    string frequencySort(string s) {
        int n=s.size();
        
        unordered_map<char,int> mp;
        
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        
        priority_queue<pip> pq;
        
        for(auto x:mp){
            pq.push({x.second, x.first});
        }
        
        string res;
        
        while(!pq.empty()){
            auto [x,y]= pq.top();
            pq.pop();
            
            while(x--){
                res+=y;
            }
        }
        
        return res;
        
    }
};