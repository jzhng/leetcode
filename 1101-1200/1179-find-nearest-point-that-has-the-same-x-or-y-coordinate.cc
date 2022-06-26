#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1, np = points.size(), minDist = INT_MAX;
        for (int i = 0; i < np; ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (minDist > dist) {
                    minDist = dist;
                    res = i;
                }
            }
        }
        return res;
    }
};
