class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n=h.size();
        
        priority_queue<int> pq;
        int i=0;
        
        for( i=1;i<n;i++){
            int diff=h[i]-h[i-1];
            
            if(diff<=0)
                continue;
            
            b-=diff;
            
            pq.push(diff);
            
            if(b<0){
                b+=pq.top();
                pq.pop();
                l--;
            }
            
            
            if(l<0)
                break;
        }
        
        return i-1;
    }
};