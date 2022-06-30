class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
            m[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto x:m)
            pq.push({x.second,x.first});
        
        string res="";
        
        while(!pq.empty()){
            
            int num=pq.top().first;
            
            for(int i=0;i<num;i++)
                res+=pq.top().second;
            
            pq.pop();
            
        }
        
        return res;
    }
};