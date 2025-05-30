class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return 0;

        int len = 2, res = 0, curDiff = nums[1] - nums[0];
        for (int i = 2; i < n; ++i) {
            int diff = nums[i] - nums[i-1];
            if  (diff == curDiff) {
                ++len;
            } else {
                if (len > 2) res += (len - 1) * (len - 2) / 2;
                curDiff = diff;
                len = 2;
            }
        }

        if (len > 2) res += (len - 1) * (len - 2) / 2;

        return res;
    }
};
