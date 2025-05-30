class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;

        int sum = 0;
        for (int n : nums) {
            if (sum < 0) sum = 0;
            sum += n;
            res = max(sum, res);
        }
        return res;
    }
};