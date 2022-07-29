class Solution {
    vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0},
    };

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int i, int j, int start, string &word) {
        if (start == word.size() - 1 && board[i][j] == word[start]) return true;
        if (board[i][j] != word[start]) return false;

        vis[i][j] = true;
        int m = board.size(), n = board[0].size();
        for (auto p: directions) {
            int x = i + p.first;
            int y = j + p.second;
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                if (dfs(board, vis, x, y, start + 1, word)) return true;
            }
        }

        vis[i][j] = false;
        return false;
    };

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, vis, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};