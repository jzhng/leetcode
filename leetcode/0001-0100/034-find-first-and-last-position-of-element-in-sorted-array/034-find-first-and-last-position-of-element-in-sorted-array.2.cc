#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int find(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (target <= nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = find(nums, target);
        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }

        int right = find(nums, target + 1);
        return {left, right - 1};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,2};
    vector<int> res = s.searchRange({nums}, 3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}