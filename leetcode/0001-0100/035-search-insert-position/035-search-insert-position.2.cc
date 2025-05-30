#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target <= nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;   // l == r
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    cout << s.searchInsert(nums, 2) << endl;
}