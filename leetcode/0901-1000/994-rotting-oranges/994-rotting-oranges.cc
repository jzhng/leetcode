#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        int rotten = 0, oranges = 0, day = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    ++rotten;
                }
                if (grid[i][j] != 0) {
                    ++oranges;
                }
            }
        }

        if (rotten == oranges) return 0;

        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            ++day;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + directions[k][0];
                    int ny = y + directions[k][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        ++rotten;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return rotten == oranges ? day : -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << s.orangesRotting(grid1) << endl;
    vector<vector<int>> grid2 = {{0}};
    cout << s.orangesRotting(grid2) << endl;
    return 0;
}