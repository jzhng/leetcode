#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), res = n+1;
        vector<int> sums(n+1);

        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }

        for (int i = 1; i <= n; ++i) {
            int t = target + sums[i-1];
            auto it = lower_bound(sums.begin(), sums.end(), t);
            if (it != sums.end()) {
                res = min(res, int(it - sums.begin()) - (i-1));
            }
        }
        return res == n + 1 ? 0 : res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums) << endl;
}