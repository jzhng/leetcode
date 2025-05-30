class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;

        int size = (sum + target) / 2;
        vector<int> dp(size + 1, 0);

        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = size; j >= nums[i]; j--) {
                dp[j] += dp[j- nums[i]];
            }
        }

        return dp[size];
    }
};
