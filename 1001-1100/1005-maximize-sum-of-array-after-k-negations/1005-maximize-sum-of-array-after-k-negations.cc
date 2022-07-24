class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        auto cmp = [](int a, int b) -> bool {
            return abs(a) > abs(b);
        };
        sort(nums.begin(), nums.end(), cmp);

        for (auto &n : nums) {
            if (n < 0 && k > 0) {
                n = -n;
                --k;
            }
            
            if (k == 0) break;
        }

        if (k % 2 == 1) nums.back() = -nums.back();

        return accumulate(nums.begin(), nums.end(), 0);
    }
};