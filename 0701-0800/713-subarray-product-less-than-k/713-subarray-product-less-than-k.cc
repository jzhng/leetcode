class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1, l = 0, r = 0, n = nums.size();

        int res = 0;
        while (l < n) {
            if (r < l) {
                r = l;
                product = 1;
            }
            while (r < n && product * nums[r] < k) {
                product *= nums[r++];
            }
            res += (r - l);
            product /= nums[l++];
        }
        return res;
    }
};