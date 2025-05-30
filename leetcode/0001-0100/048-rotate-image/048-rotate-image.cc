#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int temp = matrix[i][j];
                int x = n - 1 - j;
                int y = n - 1 - i;
                matrix[i][j] = matrix[x][i];
                matrix[x][i] = matrix[y][x];
                matrix[y][x] = matrix[j][y];
                matrix[j][y] = temp;
            }
        }

    }
};
