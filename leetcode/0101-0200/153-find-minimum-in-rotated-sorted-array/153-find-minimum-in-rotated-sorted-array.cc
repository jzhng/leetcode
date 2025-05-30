#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << s.findMin(nums) << endl;
}
