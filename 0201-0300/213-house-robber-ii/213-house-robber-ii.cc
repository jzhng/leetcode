#include <vector>
using namespace std;

class Solution {
    int robIn(vector<int>& nums, int start, int end) {
        int prev = nums[start], curr = max(nums[start], nums[start + 1]), next = 0;
        for (int i = start + 2; i <= end; ++i) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robIn(nums, 0, n-2), robIn(nums, 1, n-1));
    }
};
