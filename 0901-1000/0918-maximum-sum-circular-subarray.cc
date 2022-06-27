#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, max_pre = 0, min_pre = 0;
        int max_interval = nums[0], min_interval = nums[0];
        for (int n : nums) {
            max_pre = max(max_pre, 0) + n;
            max_interval = max(max_interval, max_pre);
            min_pre = min(min_pre, 0) + n;
            min_interval = min(min_interval, min_pre);
            total += n;
        }
        return max_interval < 0 ? max_interval : max(max_interval, total - min_interval);
    }
};
