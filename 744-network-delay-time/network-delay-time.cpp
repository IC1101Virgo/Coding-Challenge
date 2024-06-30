class Solution {
public:
    typedef pair<int,int> pi;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pi> adj[n+1];

        for(auto ele:times){
            adj[ele[0]].push_back({ele[1], ele[2]});
        }

        vector<int> dis(n+1, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        //vector<int> vis(n+1, 0);
        
        dis[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto prime = pq.top();
            pq.pop();

            int wt = prime.first, prev = prime.second;

            //vis[prev]=1;

            for(auto it:adj[prev]){
                int next = it.first, next_wt = it.second;

                if( dis[next]> dis[prev] + next_wt){
                    dis[next]=dis[prev]+next_wt;
                    pq.push({dis[next], next});
                }
            }
        }

        int ans=0;
        for(int i=1; i<=n; i++){
            if(dis[i]==INT_MAX)
            return -1;
            ans=max(ans, dis[i]);
        }

        return ans;
    }
};