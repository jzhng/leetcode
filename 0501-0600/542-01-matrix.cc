#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;
        vector<bool> visited(m*n, false);
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> res(mat);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i * n +j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < direction.size(); ++k) {
                int x = i + direction[k][0], y = j + direction[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x * n + y]) {
                    res[x][y] = res[i][j] + 1;
                    visited[x * n + y] = true;
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    auto res = s.updateMatrix(mat);
    for (auto row: res) {
        for (auto ele: row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}