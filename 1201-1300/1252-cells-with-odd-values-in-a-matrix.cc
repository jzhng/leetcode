#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> r(m), c(n);

        for (auto index: indices) {
            ++r[index[0]];
            ++c[index[1]];
        }

        int oddx = 0, oddy = 0;
        for (int i = 0; i < m; i++) {
            if (r[i] & 1) {
                oddx++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (c[i] & 1) {
                oddy++;
            }
        }
        return oddx * (n - oddy) + (m - oddx) * oddy;
    }
};
