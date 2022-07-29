class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        vector<int> positives(n,0), negatives(n, 0);

        if (nums[0] > 0) positives[0] = 1;
        if (nums[0] < 0) negatives[0] = 1;

        int res = positives[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                positives[i] = positives[i-1] + 1;
                negatives[i] = (negatives[i-1] == 0 ? 0 : negatives[i-1] + 1);
            }

            if (nums[i] < 0) {
                positives[i] = (negatives[i-1] == 0 ? 0 : negatives[i-1] + 1);
                negatives[i] = positives[i-1] + 1;
            }

            if (positives[i] > res) res = positives[i];
        }

        return res;
    }
};