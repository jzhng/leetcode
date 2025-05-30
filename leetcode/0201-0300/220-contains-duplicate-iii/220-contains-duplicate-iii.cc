/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto lb = s.lower_bound((long)nums[i] - t);
            if (lb != s.end() && *lb <= (long)nums[i] + t) {
                return true;
            }
            s.insert(nums[i]);
            if (i >= k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end

