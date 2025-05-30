#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int nr = nums.size();
        vector<int> res;
 
        int i = 0;
        while (i < nr && nums[i] < 0) {
            ++i;
        }

        int l = i - 1, r = i;
        while (l >= 0 && r < nr) {
            if (abs(nums[l]) > abs(nums[r])) {
                res.push_back(nums[r] * nums[r]);
                ++r;
            } else {
                res.push_back(nums[l] * nums[l]);
                --l;
            }
        }

        if (l < 0) {
            for (; r < nr; ++r) { res.push_back(nums[r] * nums[r]); }
        }

        if (r >= nr) {
            for (; l >= 0; --l) { res.push_back(nums[l] * nums[l]); }
        }

        return res;
    }
};