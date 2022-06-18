#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix.size() - 1;
        int n = r - l;
        while (l < r) {
            for (int i = l; i < r; ++i) {
                int t = matrix[l][i];
                matrix[l][i] = matrix[n-i][l];
                matrix[n-i][l] = matrix[n-l][n-i];
                matrix[n-l][n-i] = matrix[i][n-l];
                matrix[i][n-l] = t;
            }
            ++l; --r;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    s.rotate(matrix);
    for (auto &row : matrix) {
        for (auto &e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
}
