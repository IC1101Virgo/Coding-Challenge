class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
         int len = seats.size(), i = 0, j, res = 0;
        bool isNotTerminal;
        while (i < len) {
            // positioning i on the next 0 or end of the vector
            while (i < len && seats[i]) i++;
            j = i + 1;
            // positioning i on the next 1 or end of the vector
            while (j < len && !seats[j]) j++;
            // checking if it is a terminal series of empty spots and updating res accordingly
            isNotTerminal = i && j != len;
            res = max(res, (j - i + isNotTerminal) / (1 + isNotTerminal));
            i = j;
        }
        return res;
    }
};