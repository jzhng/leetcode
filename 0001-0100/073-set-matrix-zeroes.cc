#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && matrix[i][j] == 0) {
                    for (int k = 0; k < m; ++k) {
                        if (matrix[k][j] != 0) {
                            matrix[k][j] = 0;
                            visited[k][j] = true;
                        }

                    }
                    for (int k = 0; k < n; ++k) {
                        if (matrix[i][k] != 0) {
                            matrix[i][k] = 0;
                            visited[i][k] = true;           
                        }
                    }
                }
                visited[i][j] = true;
            }
        }
    }
};
