class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];

        vector<int> maxP(nums), minP(nums);
        for (int i = 1; i < n; ++i) {
            maxP[i] = max(nums[i], max(maxP[i-1] * nums[i], minP[i-1] * nums[i]));
            minP[i] = min(nums[i], min(maxP[i-1] * nums[i], minP[i-1] * nums[i]));
            if (maxP[i] > res) res = maxP[i];
        }
        return res;
    }
};
