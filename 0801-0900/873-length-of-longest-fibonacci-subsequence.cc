#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> indices;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            indices[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n));

        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = arr[j] - arr[i];
                if (indices.count(diff)) {
                    int k = indices[diff];
                    if (k < i) {
                        dp[i][j] = max(dp[k][i]+1, 3);
                        res = max(res, dp[i][j]);
                    }
                }
            }
        }
        return res;

    }
};