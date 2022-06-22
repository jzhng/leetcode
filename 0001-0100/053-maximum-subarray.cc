#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, res = nums[0];
        for (const auto &n : nums) {
            pre = max(pre + n, n);
            res = max(res, pre);
        }
        return res;
    }
};