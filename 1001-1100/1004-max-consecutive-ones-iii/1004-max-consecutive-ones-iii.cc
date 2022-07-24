#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        int max1 = 0, l = 0, r = 0;

        while (r < nums.size()) {
            if (nums[r] == 1) {
                ++cnt;
                max1 = max(max1, cnt);
            }
            if (r - l + 1 > max1 + k) {
                if (nums[l] == 1) --cnt;
                ++l;
            }
            ++r;
        }
        return r - l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << s.longestOnes(nums, 2) << endl;
    vector<int> nums1 = {0,0,0,0};
    cout << s.longestOnes(nums1, 0) << endl;
    return 0;
}
