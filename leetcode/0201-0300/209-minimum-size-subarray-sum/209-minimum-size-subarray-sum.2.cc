#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        int sum = 0, res = n + 1;

        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            if (sum >= target) {
                while (sum >= target + nums[l]) {
                    sum -= nums[l++];
                }
                res = min(res, r - l + 1);
            }
        }
        return res == n + 1? 0 : res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums) << endl;
}