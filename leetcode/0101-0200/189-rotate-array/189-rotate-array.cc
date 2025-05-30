#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;

        const int nr = nums.size();
        int steps = k % nr;

        for (int i = 0, j = nr - 1; i < j; ++i, --j) swap(nums[i], nums[j]);
        for (int i = 0, j = steps - 1; i < j; ++i, --j) swap(nums[i], nums[j]);
        for (int i = steps, j = nr - 1; i < j; ++i, --j) swap(nums[i], nums[j]);
    }
};