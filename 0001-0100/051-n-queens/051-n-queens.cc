class Solution {
    void backtracking(vector<vector<string>> &res, int row, vector<string> &chest) {
        int n = chest.size();

        if (row == n) {
            res.push_back(chest);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, chest)) {
                chest[row][col] = 'Q';
                backtracking(res, row + 1, chest);
                chest[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chest) {
        int n = chest.size();
        for (int i = 0; i < row; ++i) {
            if (chest[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >=0 && j < n ; --i, ++j) {
            if (chest[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; --i, --j) {
            if (chest[i][j] == 'Q') return false;
        }

        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> chest(n, string(n, '.'));
        backtracking(res, 0, chest);
        return res;
    }
};