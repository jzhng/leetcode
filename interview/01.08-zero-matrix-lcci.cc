#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int, int>> zeros;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zeros.insert({i, j});
                }
            }
        }

        for (auto &p : zeros) {
            for (int i = 0; i < m; ++i) matrix[i][p.second] = 0;
            for (int i = 0; i < n; ++i) matrix[p.first][i] = 0;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    s.setZeroes(matrix);
    for (auto &row : matrix) {
        for (auto &e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}