#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int removeDuplicates(vector<int>& nums, int k) {
        int i = 0;
        for (int x : nums) {
            if (i - k < 0 || nums[i - k] != x) {
                nums[i++] = x;
            }
        }
        return i;
    }
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates(nums, 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2};
    cout << s.removeDuplicates(nums) << endl;
}