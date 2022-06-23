#include <vector>
using namespace std;

class Solution {
    int count = 0;
    void find(vector<int>& nums, long int target, int i) {
        if (i == nums.size()) {
            if (target == 0) {
                ++count;
            }
        } else {
            find(nums, target - nums[i], i+1);
            find(nums, target + nums[i], i+1);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        find(nums, target, 0);
        return count;
    }
};