#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(costs[0]);
        for (int i = 1; i < n; ++i) {
            vector<int> dp_next(3);
            for (int j = 0; j < 3; ++j) {
                dp_next[j] = min(dp[(j+1)%3], dp[(j+2)%3]) + costs[i][j];
            }
            dp = dp_next;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
