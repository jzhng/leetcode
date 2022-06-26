#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int p = 0, q = 0, r = 0;
        for (int i = 2; i <= n; ++i) {
            r = min(p + cost[i-2], q + cost[i-1]);
            p = q;
            q = r;
        }
        return r;
    }
};
