class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1},
        };

        int step = 0;
        if (grid[0][0] == 0) {
            grid[0][0] = -1;
            q.push({0, 0});
        }
    
        while (!q.empty()) {
            int size = q.size();
            ++step;
            for (int k = 0; k < size; ++k) {
                auto p = q.front();
                q.pop();

                if (p.first == n - 1 && p.second == n - 1) return step;
                for (auto dir: directions) {
                    int x = p.first + dir[0];
                    int y = p.second + dir[1];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = -1;
                        q.push({x, y});
                    }
                }
            }
        }

        return -1;
    }
};
