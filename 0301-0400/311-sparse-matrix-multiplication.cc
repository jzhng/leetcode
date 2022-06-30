#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat2.size(), n = mat2[0].size();

        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < k; ++l) {
                    res[i][j] += mat1[i][l] * mat2[l][j];
                }
            }
        }

        return res;
    }
};
