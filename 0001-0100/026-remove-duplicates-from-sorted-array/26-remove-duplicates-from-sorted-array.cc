#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2};
    cout << s.removeDuplicates(nums) << endl;
}