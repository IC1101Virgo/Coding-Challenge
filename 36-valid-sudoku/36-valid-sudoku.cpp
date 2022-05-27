class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
              
        vector<unordered_set<int>> row(9, unordered_set<int>());
	vector<unordered_set<int>> col(9, unordered_set<int>());
	vector<unordered_set<int>> boxes(9, unordered_set<int>());

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
               if (board[i][j] == '.')
		  continue;

		int num = board[i][j]-'1' ;

		if (row[i].count(num))
		  return false;

		if (col[j].count(num))
		  return false;

		// This is a straight-forward math formula to locate a box
		// Out of the 9 boxes
		int box = (i / 3) * 3 + j / 3;

		if (boxes[box].count(num))
		  return false;

		row[i].insert(num);
		col[j].insert(num);
		boxes[box].insert(num);
                
            }
        }
        
        return true;
    }
};