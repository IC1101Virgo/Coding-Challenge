class Solution {
public:
     int answer;
    void minimumTimeRequiredHelper(vector<int>& jobs, int index, int n, int k,
                                  vector<int>& workersMap) {
        if (index == n) {
            int temp = INT_MIN;
            for (auto& val : workersMap) {
                temp = max(temp, val);
            }
            answer = min(temp, answer);
            return;
        }
        
        unordered_set<int> seen;
        for (int i = 0; i < k; i++) {
            if (seen.find(workersMap[i]) != seen.end()) continue;
            if (workersMap[i] + jobs[index] > answer) continue;
            seen.insert(workersMap[i]);
            workersMap[i] = workersMap[i] + jobs[index];
            minimumTimeRequiredHelper(jobs, index + 1, n, k, workersMap);
            workersMap[i] = workersMap[i] - jobs[index];
        }
    }
    int distributeCookies(vector<int>& jobs, int k) {
         int n = jobs.size();
        vector<int> workersMap(k, 0);
        answer = INT_MAX;
        minimumTimeRequiredHelper(jobs, 0, n, k, workersMap);
        return answer;
    }
};