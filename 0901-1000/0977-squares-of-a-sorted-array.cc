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

        int l = i-1, r = i;
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
            while (r < nr) { res.push_back(nums[r] * nums[r]); ++r; }
        }

        if (r >= nr) {
            while (l >= 0) { res.push_back(nums[l] * nums[l]); --l; }
        }

        return res;
    }
};