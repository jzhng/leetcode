#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (target <= nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int left = l;

        l = 0, r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (target < nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int right = l - 1;

        if (left < n && nums[left] == target) {
            return {left, right};
        }

        return {-1, -1};
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