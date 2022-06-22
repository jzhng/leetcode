#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = 1 + (r - l) >> 1;
            if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    cout << s.searchInsert(nums, 2) << endl;
}