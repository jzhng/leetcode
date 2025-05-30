#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int &x: nums) {
            if (x) {
                swap(x, nums[l++]);
            }
        }
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int l = 0, r = 0;
//         while (r < nums.size()) {
//             if (nums[r]) {
//                 if (l != r) swap(nums[l], nums[r]);
//                 ++l;
//             }
//             ++r;
//         }
//     }
// };