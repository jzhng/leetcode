class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), res = 1;

        vector<int> dp(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < nums[i+1]) {
                dp[i+1] = dp[i] + 1;
            }
            if (dp[i+1] > res) res = dp[i+1];
        }
        return res;
    }
};
