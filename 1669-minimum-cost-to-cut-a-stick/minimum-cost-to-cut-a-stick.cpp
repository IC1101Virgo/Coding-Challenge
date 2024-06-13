class Solution {
public:
    int dp[102][102];
    int solve(vector<int> &cuts, int l, int r){
        if(r-l<=1)
        return 0;

        if(dp[l][r]!=-1) 
        return dp[l][r];

        int cost = 1e9;

        for(int i=l+1; i<=r-1; i++)
        {
            int l_cost= solve( cuts, l, i);
            int r_cost= solve( cuts, i, r);
            int c_cost = (cuts[r]-cuts[l])+l_cost+r_cost;
            cost = min(cost, c_cost);
        }

        return dp[l][r] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size()-1);

    }
};