#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();
        if (m == 0) return res;
        
        int n = matrix[0].size();
        int l = 0, r = n - 1, t = 0, b = m - 1;

        while (l <= r && t <= b) {
            for (int i = l; i <= r; ++i) res.push_back(matrix[t][i]);
            ++t;
            for (int i = t; i <= b; ++i) res.push_back(matrix[i][r]);
            --r;
            for (int i = r; i >= l && t <= b; --i) res.push_back(matrix[b][i]);
            --b;
            for (int i = b; i >= t && l <= r; --i) res.push_back(matrix[i][l]);
            ++l;
        }
        return res;
    }
};
