class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        
        for(auto x:mp){
            pq.push({x.second, x.first});
        }
        
        string res="";
        
        while(pq.size()>1){
            auto [x1,y1]= pq.top();
            pq.pop();
            
            auto [x2,y2]=pq.top();
            pq.pop();
            
            res=res+y1+y2;
            
            x1--; x2--;
            
            if(x1>0)
                pq.push({x1,y1});
            
            if(x2>0)
                pq.push({x2,y2});

        }
        
        if(!pq.empty())
        {
            if(pq.top().first>1)
                return "";
            
            else res+=pq.top().second;
            
        }
        return res;
        
    }
};