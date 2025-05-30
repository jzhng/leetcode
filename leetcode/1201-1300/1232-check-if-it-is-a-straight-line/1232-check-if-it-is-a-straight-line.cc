#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int m = coordinates.size();
        if (m == 2) return true;
        for (int i = 0; i < m - 2; ++i) {
            int x1 = coordinates[i][0], y1 = coordinates[i][1];
            int x2 = coordinates[i+1][0], y2 = coordinates[i+1][1];
            int x3 = coordinates[i+2][0], y3 = coordinates[i+2][1];
            if ((y3 - y2) * (x2 - x1) != (y2 - y1) * (x3 -x2)) {
                return false;
            }
        }
        return true;
    }
};
