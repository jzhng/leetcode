#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_right = 0;
        for (auto n: nums) {
            sum_right += n;
        }

        int sum_left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum_right -= nums[i];
            if (i > 0) sum_left += nums[i-1];
            if (sum_left == sum_right) {
                return i;
            }
        }
        return -1;
    }

    // int pivotIndex(vector<int>& nums) {
    //     int total = accumulate(nums.begin(), nums.end(), 0);
    //     int sum = 0;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         if (sum * 2 + nums[i] == total) {
    //             return i;
    //         }
    //         sum += nums[i];
    //     }
    //     return -1;
    // }
};

int main() {
    Solution s;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(nums) << endl;
}