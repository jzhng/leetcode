#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0, r = n - 1;

        int cnt = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        while (l < r) {
            int i = l, j = l;
            for (; j < r; ++j) matrix[i][j] = cnt++;
            for (; i < r; ++i) matrix[i][j] = cnt++;
            for (; j > l; --j) matrix[i][j] = cnt++;
            for (; i > l; --i) matrix[i][j] = cnt++;
            ++l; --r;
        }

        if (l == r) matrix[l][l] = cnt;
        return matrix;
    }
};
