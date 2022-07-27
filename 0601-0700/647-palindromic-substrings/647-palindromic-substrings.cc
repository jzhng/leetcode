class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j <= n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1 || dp[i+1][j-1]) {
                        ++res;
                        dp[i][j] = true;
                    }
                }
            }
        }

        return res;
    }
};