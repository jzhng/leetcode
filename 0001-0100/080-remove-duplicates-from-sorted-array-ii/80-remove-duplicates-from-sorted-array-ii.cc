#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int k = 2;
        int i = 0;
        for (auto &n : nums) {
            if (i < k || n != nums[i-k]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 1, 1, 2, 2};
    int len = s.removeDuplicates(nums);
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}