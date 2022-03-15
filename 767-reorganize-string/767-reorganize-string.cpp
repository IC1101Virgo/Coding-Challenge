class Solution {
public:
    string reorganizeString(string s) {
        string res="";
        
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        
        for(auto x:s){
            m[x]++;
        }
        
        for(auto y:m){
            pq.push(make_pair(y.second,y.first));
        }
        
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            
            top1.first-=1;
            top2.first-=1;
            
            res+=top1.second;
            res+=top2.second;
            
            if(top1.first>0)
                pq.push(top1);
            
            if(top2.first>0)
                pq.push(top2);
        }
        
        if(!pq.empty()){
            if(pq.top().first>1)
                return "";
            
            else res+=pq.top().second;
        }
        
        return res;
    }
};