#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for (auto &n : nums) {
            ++cnt[n];
        }

        int k = 0;
        for (int i = 0; i < 3; i++) {
            while (--cnt[i] >= 0) {
                nums[k++] = i;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (auto &n : nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
