class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int maxLen = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) dp[i][0] = matrix[i][0] - '0';
        for (int j = 0; j < n; ++j) dp[0][j] = matrix[0][j] - '0';

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    }
                    if (maxLen < dp[i][j]) maxLen = dp[i][j];
                }
            }
        }
        return maxLen * maxLen;
    }
};
