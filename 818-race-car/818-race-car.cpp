class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0, 1, 1}); // pos, speed, direction +1 or -1
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto v = move(q.front());
                q.pop();
                
                if (v[0] == target) return cnt;
                
                if (abs(v[0]) <= 2*target) {
                    q.push({v[0]+v[1]*v[2], v[1]*2, v[2]});
					// if R is meaningful
                    if ((v[0]+v[1]*v[2] > target && v[2] > 0) || (v[0]+v[1]*v[2] < target && v[2] < 0))
                        q.push({v[0], 1, -v[2]});
                }
            }
            cnt++;
        }
        return -1;
    }
};