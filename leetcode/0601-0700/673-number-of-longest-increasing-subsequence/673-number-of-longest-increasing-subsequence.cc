class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, maxLen = 0;
        int n = nums.size();

        vector<int> dp(n, 1), cnt(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }

            if (dp[i] == maxLen) {
                res += cnt[i];
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                res = cnt[i];
            }
        }

        return res;
    }
};
