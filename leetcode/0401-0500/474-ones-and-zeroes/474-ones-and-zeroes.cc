class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (string s: strs) {
            int cntZero = 0;
            for (char c: s) {
                if (c == '0') ++cntZero;
            }
            int cntOne = s.size() - cntZero;

            for (int i = m; i >= cntZero; --i) {
                for (int j = n; j >= cntOne; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - cntZero][j - cntOne] + 1);
                }
            }
        }

        return dp[m][n];
    }
};