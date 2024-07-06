class Solution {
public:
    vector<int> parent;

    int find_s(int x){
        if(parent[x] == x)
        return x;

        else return find_s(parent[x]);
    }

    void make_union(int a, int b){
        int aa = find_s(a), bb= find_s(b);

        if(aa!=bb)
        parent[aa] = bb;

    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);

        unordered_map<string, int> mp;

        for(int i=0; i<n; i++){
            parent[i] = i;

            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    make_union(mp[accounts[i][j]], i);
                }

                else mp[accounts[i][j]] = parent[i];
            }
        }

        unordered_map<int, vector<string>> newacc;

        for(auto it:mp){
            newacc[find_s(it.second)].push_back(it.first);
        }

        vector<vector<string>> res;

        for(auto it: newacc){
            auto mail = it.second;

            sort(mail.begin(), mail.end());
            mail.insert(mail.begin(), accounts[it.first][0]);

            res.push_back(mail);
        }

        return res;


    }
};