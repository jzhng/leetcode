#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j]) nums[i++] = nums[j];
        }

        for (int j = i; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}