class Solution {
public:
    typedef pair<int,char> pi;
    string frequencySort(string s) {
        int n=s.size();
        
        unordered_map<char,int>mp;
        
        for(auto x:s)
            mp[x]++;
        
        priority_queue<pi>pq;
        
        for(auto x:mp)
            pq.push({x.second,x.first});
        
        string res="";
        
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            
            int size=temp.first;
            
            for(int i=0;i<size;i++)
                res+=temp.second;
        }
        
        return res;
    }
};