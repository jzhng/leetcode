#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return r + 1; // l == r + 1
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    cout << s.searchInsert(nums, 2) << endl;
}