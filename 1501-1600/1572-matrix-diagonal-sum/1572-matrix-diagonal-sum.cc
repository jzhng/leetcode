#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();

        int x = 0, y = 0, sum = 0;
        for (int i= 0; i < m; ++i) sum += mat[x++][y++];

        x = 0;
        y = m - 1;
        for (int i = 0; i < m; ++i) sum += mat[x++][y--];

        if (m % 2) sum -= mat[m/2][m/2];

        return sum;
    }
};