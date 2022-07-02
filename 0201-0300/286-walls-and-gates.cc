#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();

        vector<vector<int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int level = 0;
        while (!q.empty()) {
            ++level;
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto [x, y] = q.front();
                q.pop();
                for (auto d: dir) {
                    int xx = x+d[0], yy = y+d[1];
                    if (xx >= 0 && xx <m && yy >= 0 && yy <n && rooms[xx][yy] == INT_MAX) {
                        rooms[xx][yy] = level;
                        q.push({xx, yy});
                    }
                }
            }
        }
  }
};