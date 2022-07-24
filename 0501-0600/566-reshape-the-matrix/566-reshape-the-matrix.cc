#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n) return mat;

        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; ++i) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {
        {1, 2, 3, 4}
    };
    vector<vector<int>> res = s.matrixReshape(mat, 2, 2);
    for (auto &r : res) {
        for (auto &c: r) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
