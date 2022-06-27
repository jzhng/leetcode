#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        int maxn = 0;
        for (auto n: nums) {
            maxn = max(maxn, n);
            points[n] += n;
        }

        vector<int> dp(maxn+1);
        if (maxn == 1) return points[1];
        dp[1] = points[1];
        dp[2] = max(points[1], points[2]);
        for (int i = 3; i <= maxn; ++i) {
            dp[i] = max(dp[i-2] + points[i], dp[i-1]);
        }
        return dp[maxn];
    }
};
