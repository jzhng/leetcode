class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(matrix);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int pre = dp[i-1][j];
                if (j == 0) {
                    pre = min(pre, dp[i-1][j+1]);
                } else if (j == n - 1) {
                    pre = min(pre, dp[i-1][j-1]);
                } else {
                    pre = min(pre, min(dp[i-1][j-1], dp[i-1][j+1]));
                }
                dp[i][j] = pre + matrix[i][j];
            }
        }

        int minSum = dp[n-1][0];
        for (int i = 1; i < n; ++i) {
            if (minSum > dp[n-1][i]) minSum = dp[n-1][i];
        }
        return minSum;
    }
};
