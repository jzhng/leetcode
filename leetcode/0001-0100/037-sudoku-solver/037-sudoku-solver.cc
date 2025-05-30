class Solution {
    bool backtracking(vector<vector<char>>& board) {
        const int n = 9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') continue;
                for (char c = '1'; c <= '9'; ++c) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
        }

        int startRow = row/3 * 3;
        int startCol = col/3 * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == c) return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};